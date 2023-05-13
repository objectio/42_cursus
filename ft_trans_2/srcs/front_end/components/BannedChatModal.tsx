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
import { useRouter } from "next/router";

export default function BannedChatModal({
	userData,
	userMe,
}: {
	userData: any;
	userMe: any;
}) {
	const { chatSocket: socket } = useContext(SocketContext);
	const me = userMe[0];
	const router = useRouter();

	function BanUser(event: React.MouseEvent<HTMLElement>, item: any) {
		event.preventDefault();
		socket?.emit("toggleBanUser", {userId: item.id}, (error: any) => {
			if (!error.status) {
				console.log(error); // 서버에서 전달된 에러 메시지 출력
				router.push(`/lobby/chat/`);
			}
		});
	}

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
						{(me.role === 0 || me.role === 1) &&
						me.user.name !== user.user.name ? (
							<>
								<Menu.Item>
									{({ active }) => (
										<button
											className={clsx(
												active
													? "bg-red-400 text-white"
													: "bg-red-500 text-white",
												"block w-full rounded px-4 py-2 text-sm"
											)}
											onClick={(e) => BanUser(e, user.user)}
										>
											BAN 해제
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
