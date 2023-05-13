import Layout from "@/components/Layout";
import Image from "next/image";
import Loading from "@/components/ui/Loading";
import SlideButton from "@/components/ui/SlideButton";
import { ReactElement, useContext, useEffect, useState } from "react";
import { useRouter } from "next/router";
import {
	ChatBubbleLeftRightIcon,
	QueueListIcon,
	NoSymbolIcon
} from "@heroicons/react/24/outline";
import {
	SocketContext,
	SocketProvider,
} from "@/lib/socketContext";
import { NextPageWithLayout } from "@/pages/_app";
import { toast } from "react-toastify";
import { Socket } from "socket.io-client";

const ChatRooms: NextPageWithLayout = () => {
	const [loading, setLoading] = useState(true);
	const [activeTab, setActiveTab] = useState("chat");
	const [name, setName] = useState("");
	const [isPrivate, setIsPrivate] = useState(false);
	const [password, setPassword] = useState("");
	const [showCreateRoomPopup, setShowCreateRoomPopup] = useState(false);
	const [chatRooms, setChatRooms] = useState([]);
	const [DMLists, setDMLists] = useState([]);
	const router = useRouter();

	// socket 연결
	const { friendSocket, chatSocket } = useContext(SocketContext);
	useEffect(() => {
		friendSocket?.emit("updateActiveStatus", 2);
	}, [friendSocket]);

	function showChatRoomList(data: any) {
		// console.log("chatrooms data : ", data);
	}

	useEffect(() => {
		const handleRouteChangeStart = (url: string) => {
			if (!url.match(/^\/lobby\/chat(?:\/)?(?:\/.*)?$/)) {
				chatSocket?.emit("leaveChatPage");
				// console.log("페이지를 떠납니다.");
			}
		};
		chatSocket?.on("showChatRoomList", function (data) {
			console.log(data);
			setChatRooms(data);
			setLoading(false);
			showChatRoomList(data);
		})
	
		chatSocket?.on("showDirectMessageList", function(data) {
			setDMLists(data);
			console.log("dm room list", data);
			showChatRoomList(data);
		})

		chatSocket?.emit("enterChatLobby");
		router.events.on("routeChangeStart", handleRouteChangeStart);
		return () => {
			chatSocket?.off("showChatRoomList");
			chatSocket?.off("showDirectMessageList");
			router.events.off("routeChangeStart", handleRouteChangeStart);
		};
	}, [chatSocket, router]);



	const createChatRoom = () => {
		setLoading(true);
		const roomType = isPrivate === true ? "PROTECTED" : "PUBLIC";
		chatSocket?.emit('createChatRoom', {
			name,
			type: String(roomType),
			password
		  }, (callback: any) => {
			if (!callback.status) {
				toast.error(callback.message); // 서버에서 전달된 에러 메시지 출력
				setLoading(false);
			} else {
				toast.success(callback.message); // 서버에서 전달된 메시지 출력
				router.push(`/lobby/chat/${name}?isProtected=${isPrivate}`);
			}
		  });
		setShowCreateRoomPopup(false);
	  };
	  const joinChatRoom = (room: any) => {
		if (room.type === "PROTECTED") {
		  router.push(`/lobby/chat/${room.name}?isProtected=true`);
		}
		else
		{
			router.push(`/lobby/chat/${room.name}?isProtected=false`);
		}
	  };
	
	  const joinDMRoom = (room: any) => {
		chatSocket?.emit("enterDirectMessage", {
			directMessageId: room.id,
		});
		router.push(`/lobby/chat/dm/dm: ${room.otherUserName}?dmId=${room.id}`);
	};

	  const handleTabClick = (tab: string) => {
		setActiveTab(tab);
	  };

	return (
		<div className="relative flex flex-1 flex-col gap-4">
			<div className="grid grid-cols-1 gap-3 p-3 mt-4 -mb-8">
				<div className="flex gap-4 divide-zinc-400 content-start">
					<div className={`${activeTab === "chat"
							? "bg-white text-zinc-800"
							: "text-indigo-200 hover:bg-zinc-700 hover:text-white"}
						group flex gap-x-3 rounded-md px-3.5 py-2 text-xl font-semibold leading-6
					`}
					onClick={() => handleTabClick("chat")}
					style={{ cursor: "pointer" }}
					>
					<QueueListIcon className="h-6 w-6 shrink-0"/>
						나의 채팅방 목록
					</div>
					<div className={`${activeTab === "DM"
					? "bg-white text-zinc-800"
					: "text-indigo-200 hover:bg-zinc-700 hover:text-white border"}
						group flex gap-x-3 rounded-md px-3.5 py-2 text-xl font-semibold leading-6
					`}
					onClick={() => handleTabClick("DM")}
					style={{ cursor: "pointer" }}
					>
					<ChatBubbleLeftRightIcon className="h-6 w-6 shrink-0"/>
						1:1 채팅
					</div>
				</div>
			</div>
		{ activeTab === "chat" ? (
		<div className="container mx-auto py-6">
			<div className="grid grid-cols-1 gap-3 rounded-lg bg-zinc-600 p-5">
				<div className="flex divide-x-4 divide-zinc-400 content-start">
					<div className="flex w-1/4 flex-col items-center justify-center text-base">
						<p className="text-[#bbc2ff]">채팅방 이름</p>
					</div>
					<div className="flex w-1/4 flex-col items-center justify-center space-y-3 text-base">
						<p className="text-[#bbc2ff]">인원</p>
					</div>
					<div className="flex w-1/4 flex-col items-center justify-center space-y-3 text-base">
						<p className="text-[#bbc2ff]">공개 채널</p>
					</div>
					<div className="flex w-1/4 flex-col items-center justify-center space-y-3 text-base">
						<p className="text-[#bbc2ff]">입장</p>
					</div>
				</div>
					<>
					{loading ? (
					<>
						<Loading />
					</>
					) : (
					chatRooms.map((room: any) => (
					<div key={room.id} className="bg-zinc-800 text-white p-4 rounded-lg shadow">
						<div className="flex divide-x-4 divide-zinc-800">
							<div className="flex w-1/4 flex-col items-center justify-center space-y-3 text-base">
								<p className="font-bold">{room.name}</p>
							</div>
							<div className="flex w-1/4 flex-col items-center justify-center space-y-3 text-base">
								<p className="font-bold">{room.users.length || '---'}</p>
							</div>
							<div className="flex w-1/4 flex-col items-center justify-center space-y-3 text-base">
								<p className="font-bold">{room.type === "PROTECTED" ? '비공개' : '공개'}</p>
							</div>
							<div className="flex w-1/4 flex-col items-center justify-center space-y-3 text-base">
								<button onClick={() => joinChatRoom(room)} className="rounded-lg bg-zinc-400 p-3 hover:bg-zinc-700 transition-colors cursor-pointer">입장</button>
							</div>
						</div>
					</div>
					))
					)}
					</>
					</div>
			</div>
			) :
			<div className="container mx-auto py-6">
			<div className="grid grid-cols-1 gap-3 rounded-lg bg-zinc-600 p-5">
						{/* Replace this array with actual game room data */}
					<>
					{loading ? (
					<>
						<Loading />
					</>
					) : (
					DMLists.map((room: any) => (
					<div key={room.id} className="bg-zinc-800 text-white p-4 rounded-lg shadow">
						<div className="flex divide-x-4 divide-zinc-800">
							<div className="z-20 flex">
								<Image
									className="h-12 w-12 rounded-full bg-zinc-800 shadow ring-8 ring-zinc-800 sm:h-12 sm:w-12"
									src={room.otherUserAvatarImageUrl}
									alt=""
									width={100}
									height={100}
								/>
							</div>
							<div className="flex w-1/4 flex-col items-center justify-center space-y-3 text-base">
								<p className="font-bold">{room.otherUserName + "\t님과의 대화방"}</p>
							</div>
							{room.isBlocked === true  ? (
							<div className="flex w-1/4 flex-col items-end justify-end space-y-3 text-base">
								<NoSymbolIcon className="ml-auto h-12 w-12 text-red-500"/>
							</div>
							): <></>}
							<div className="flex w-1/4 flex-col items-end justify-end space-y-3 text-base flex-grow">
								<button onClick={() => joinDMRoom(room)} className="rounded-lg bg-zinc-400 p-3 hover:bg-zinc-700 transition-colors cursor-pointer">대화</button>
							</div>
						</div>
					</div>
					))
					)}
					</>
					</div>
			</div>}
			<button className="fixed bottom-[60px] right-[60px] max-w-[200px] min-w-[62px] h-[62px] z-[3] bg-gradient-to-r from-cyan-500 to-blue-500 from-main1 to-main2 rounded-[20px] flex justify-center items-center transition-all duration-300 ease-in-out group px-[17px] hover:pr-[25px]">
				<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 20 20" fill="currentColor" aria-hidden="true" className="text-white w-[1.787rem]​ h-[1.787rem]​">
				<path fillRule="evenodd" d="M10 3a1 1 0 011 1v5h5a1 1 0 110 2h-5v5a1 1 0 11-2 0v-5H4a1 1 0 110-2h5V4a1 1 0 011-1z" clipRule="evenodd">
				</path>
				</svg>
				<span className="overflow-hidden inline-flex whitespace-nowrap max-w-0 group-hover:!max-w-[140px] text-white font-semibold group-hover:ml-[12px] transition-all duration-300 ease-in-out">채팅방 생성</span>
			</button>
			<div className="absolute bottom-5 right-8 ...">

				<div className="flex -mt-12 w-24 flex-col items-center justify-center space-y-3 text-sm">
					{!showCreateRoomPopup && <SlideButton onClick={() => setShowCreateRoomPopup(true)} />}
					{showCreateRoomPopup && <SlideButton onClick={() => setShowCreateRoomPopup(false)} />}
					{showCreateRoomPopup && (
						<div className="fixed outline outline-offset-4 outline-cyan-600 top-1/2 left-1/2 justify-items-center transform -translate-x-1/2 -translate-y-1/2 grid rounded bg-zinc-900 gap-4">
							<p className="text-lg font-medium mt-4 text-center text-white">방 제목</p>
							<input
								type="text"
								value={name}
								onChange={(e) => setName(e.target.value)}
								className="bg-black text-white px-2 py-2 rounded-md mb-3"
							/>
								<div className="flex grid grid-cols-2">
									<div className="flex">
										<input
										type="checkbox"
										checked={isPrivate}
										onChange={() => setIsPrivate(prevState => !prevState)}
										className="mt-1 ml-2 rounded-md bg-black checked:bg-blue-600 "
										/>
									</div>
									<p className="text-lg -mt-1 -ml-8 font-medium text-white">비밀번호 설정</p>

								</div>
							{isPrivate &&
							(
								<input
									type="text"
									value={password}
									onChange={(e) => setPassword(e.target.value)}
									className="rounded-md w-48 bg-black px-3 py-2 text-white"
								/>
							)
							}
							<button onClick={createChatRoom} className="w-20 mb-4 rounded-lg place-items-center text-black font-bold bg-white p-3 hover:bg-green-600 transition-colors cursor-pointer">생성</button>
						</div>
					)}
				</div>
			</div>
		</div>
	);
};



ChatRooms.getLayout = function getLayout(page: ReactElement) {
	return (
		<SocketProvider>
			<Layout>{page}</Layout>
		</SocketProvider>
	);
};

export default ChatRooms;
