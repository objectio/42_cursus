import Link from "next/link";
import Image from "next/image";
import DefaultAvatarPic from "@/public/default_avatar.svg";
import clsx from "clsx";
import { Fragment, useContext } from "react";
import { Menu, Transition } from "@headlessui/react";
import { SocketContext } from "@/lib/socketContext";
import { ExclamationCircleIcon } from "@heroicons/react/24/outline";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faCertificate, faCrown } from "@fortawesome/free-solid-svg-icons";
import { NotifyContext } from "@/lib/notifyContext";
import { useRouter } from "next/router";

export default function ChatModal({
	userData,
	userMe,
}: {
	userData: any;
	userMe: any;
}) {
	const { chatSocket: socket } = useContext(SocketContext);
	const { gameSocket: gameSocket } = useContext(SocketContext);
	const me = userMe[0];
	console.log("chatmodal me data:", me);
	console.log("chatmodal user data:", userData);
	// console.log("meid : ", userMe.user.id);
	// console.log("meid : ", user.user.id);
	const router = useRouter();

	function KickUser(event: React.MouseEvent<HTMLElement>, item: any) {
		event.preventDefault();
		console.log("kick user name : ", item);
		socket?.emit("kickUser", {userId: item.id}, (error) => {
			if (!error.status) {	
				console.log(error); // 서버에서 전달된 에러 메시지 출력
				router.push(`/lobby/chat/`);
			}
		});
	}

	function BanUser(event: React.MouseEvent<HTMLElement>, item: any) {
		event.preventDefault();
		socket?.emit("toggleBanUser", {userId: item.id}, (error) => {
			if (!error.status) {
				console.log(error); // 서버에서 전달된 에러 메시지 출력
				router.push(`/lobby/chat/`);
			}
		});
	}

	function MuteUser(event: React.MouseEvent<HTMLElement>, item: any) {
		event.preventDefault();
		socket?.emit("setMuteUser", {userId: item.id}, (error) => {
			if (!error.status) {
				console.log(error); // 서버에서 전달된 에러 메시지 출력
				router.push(`/lobby/chat/`);
			}
		});
	}

	function SetAdmin(event: React.MouseEvent<HTMLElement>, item: any) {
		event.preventDefault();
		socket?.emit("setAdmin", {userId: item.id}, (error) => {
			if (!error.status) {
				console.log(error); // 서버에서 전달된 에러 메시지 출력
			}
		});
	}

	const { successed } = useContext(NotifyContext);
	function onSuccessed() {
		successed({
			header: "게임요청",	
			message: "게임요청을 성공적으로 보냈습니다.",
		});
	}

	const createDirectMessage = (id: string, name: string) => {
		console.log("1:1 data: ", id, name);
		socket?.emit("createDirectMessage", {
			receiverId: id,
		}, (res: any) => {
			console.log("res", res);
			router.push(`/lobby/chat/dm/dm: ${name}?dmId=${res.directMessageId}`);
			if (!res.status) {
				console.log(res); // 서버에서 전달된 에러 메시지 출력
				router.push(`/lobby/chat/`);
			}
		});

	};

	// 게임 초대 이벤트
	const inviteUserForGame = (event: React.MouseEvent<HTMLElement>, item: any) => {

		// console.log('user: ', item)

		gameSocket?.emit("inviteUserForGame", { userName: item.name });
		gameSocket?.on("error", (error) => {
			console.log(error); // 서버에서 전달된 에러 메시지 출력
		});
		gameSocket?.on('getMatching', (data: string, roomId: string) => {
			// console.log(`getMatching: ${data}`);

			if (data == 'matching')	{
				// console.log(data2);
				router.push(`/lobby/game/${roomId}`);
			}	else {
				alert('매칭 실패');
			}
		})
		// router.push(`game`);
		onSuccessed();
	};



	return userData.map((user: any, index: number) => (
		me ? 
		<Menu as="li" key={index}>
			<div className="bg-black"></div>
			<Menu.Button className="group flex w-full items-center gap-x-4 rounded-md p-2 text-sm font-normal leading-6 text-indigo-200 hover:bg-zinc-700 hover:text-white">
				<Image
					className="inline-block h-7 w-7 flex-none rounded-full"
					src={DefaultAvatarPic}
					alt=""
				/>
				<span className="mr-auto">{user.user.name}</span>
				{user.role === 0 ? (
					<FontAwesomeIcon
						icon={faCrown}
						className="ml-auto h-4 w-4 text-yellow-500"
					/>
				) : user.role === 1 ? (
					<FontAwesomeIcon
						icon={faCertificate}
						className="ml-auto h-4 w-4 text-green-600"
					/>
				) : (
					<></>
				)}
			</Menu.Button>
			<Transition
				as={Fragment}
				enter="transition ease-out duration-100"
				enterFrom="transform opacity-0 scale-95"
				enterTo="transform opacity-100 scale-100"
				leave="transition ease-in duration-75"
				leaveFrom="transform opacity-100 scale-100"
				leaveTo="transform opacity-0 scale-95"
			>
				<Menu.Items className="absolute right-4 z-10 mt-2 w-48 origin-top-right rounded bg-zinc-950 shadow-lg ring-1 ring-black ring-opacity-5 focus:outline-none">
					<div>
						<Menu.Item>
							{({ active }) => (
								<button
									type="button"
									className={clsx(
										active ? "bg-gray-100 text-gray-700" : "text-white",
										"block w-full rounded-t px-4 py-2 text-sm"
									)}
									onClick={() => router.push(`/lobby/users/${user.user.id}`)}
								>
									유저 정보
								</button>
							)}
						</Menu.Item>
						{me.user.name !== user.user.name && (
							<Menu.Item>
								{({ active }) => (
									<button
										className={clsx(
											active ? "bg-gray-100 text-gray-700" : "text-white",
											"block w-full px-4 py-2 text-sm"
										)}
										onClick={(e) => createDirectMessage(user.user.id, user.user.name)}
									>
										1:1 채팅
									</button>
								)}
							</Menu.Item>
						)}
						{me.user.name !== user.user.name && (
							<Menu.Item>
								{({ active }) => (
									<button
										className={clsx(
											active ? "bg-gray-100 text-gray-700" : "text-white",
											"block w-full px-4 py-2 text-sm"
										)}
										onClick={(e) => { inviteUserForGame(e, user.user) }}
									>
										게임 초대
									</button>
								)}
							</Menu.Item>
						)}
						{(me.role === 0 || me.role === 1) &&
						me.user.name !== user.user.name ? (
							<>
								<Menu.Item>
									{({ active }) => (
										<button
											className={clsx(
												active ? "bg-gray-100 text-gray-700" : "text-white",
												"block w-full px-4 py-2 text-sm"
											)}
											onClick={(e) => SetAdmin(e, user.user)}
										>
											관리자 임명
										</button>
									)}
								</Menu.Item>
								<Menu.Item>
									{({ active }) => (
										<button
											className={clsx(
												active ? "bg-gray-100 text-gray-700" : "text-white",
												"block w-full px-4 py-2 text-sm"
											)}
											onClick={(e) => KickUser(e, user.user)}
										>
											KICK
										</button>
									)}
								</Menu.Item>
								<Menu.Item>
									{({ active }) => (
										<button
											className={clsx(
												active ? "bg-gray-100 text-gray-700" : "text-white",
												"block w-full px-4 py-2 text-sm"
											)}
											onClick={(e) => MuteUser(e, user.user)}
										>
											MUTE
										</button>
									)}
								</Menu.Item>
								<Menu.Item>
									{({ active }) => (
										<button
											className={clsx(
												active
													? "bg-red-400 text-white"
													: "bg-red-500 text-white",
												"block w-full rounded-b px-4 py-2 text-sm"
											)}
											onClick={(e) => BanUser(e, user.user)}
										>
											BAN
										</button>
									)}
								</Menu.Item>
							</>
						) : (
							<></>
						)}
					</div>
				</Menu.Items>
			</Transition>
		</Menu>
		: <></>
	));
}
