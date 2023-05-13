import { Fragment, useContext, useEffect } from "react";
import { Transition } from "@headlessui/react";
import { CheckCircleIcon } from "@heroicons/react/24/outline";
import { XMarkIcon } from "@heroicons/react/20/solid";
import { NotifyContext } from "@/lib/notifyContext";
import clsx from "clsx";
import Image from "next/image";
import {useRouter} from "next/router";
import { SocketContext } from "@/lib/socketContext";

export default function ChatNotification() {
	// Context 사용
	const { show, isSuccessed, header, message, id, close } =
		useContext(NotifyContext);

	// 5초 후 알림창 닫기
	useEffect(() => {
		if (show) {
			setTimeout(() => {
				close();
			}, 5000);
		}
	}, [close, show]);

	const router = useRouter();

	const { chatSocket } = useContext(SocketContext);
	const moveToDirectMessage = () => {
		// chatSocket?.emit("enterDirectMessage", {
		// 	directMessageId: id,
		// });
		chatSocket?.on("error", (error) => {
			console.log(error); // 서버에서 전달된 에러 메시지 출력
		});
		router.push(`/lobby/chat/dm/dm: ${header}?dmId=${id}`);
	};

	return (
		<>
			{/* Global notification live region, render this permanently at the end of the document */}
			<div
				aria-live="assertive"
				className="pointer-events-none fixed inset-0 z-100 flex items-end px-4 py-6 sm:items-start sm:p-6"
			>
				<div className="flex w-full flex-col items-center space-y-4 sm:items-end">
					{/* Notification panel, dynamically insert this into the live region when it needs to be displayed */}
					<Transition
						show={show}
						as={Fragment}
						enter="transform ease-out duration-300 transition"
						enterFrom="translate-y-2 opacity-0 sm:translate-y-0 sm:translate-x-2"
						enterTo="translate-y-0 opacity-100 sm:translate-x-0"
						leave="transition ease-in duration-0"
						leaveFrom="opacity-100"
						leaveTo="opacity-0"
					>
						<div onClick={moveToDirectMessage} className="pointer-events-auto cursor-pointer flex w-full max-w-md rounded-lg bg-white shadow-lg ring-1 ring-black ring-opacity-5">
							<div className="w-0 flex-1 p-4">
								<div className="flex items-start">
									<div className="flex-shrink-0 pt-0.5">
										<Image
											className="h-10 w-10 rounded-full bg-zinc-800 p-2"
											src="/default_avatar.svg"
											width={160}
											height={160}
											alt=""
										/>
									</div>
									<div className="ml-3 w-0 flex-1">
										<p className="text-sm font-medium text-gray-900">
											{header}
										</p>
										<p className="mt-1 text-sm text-gray-500">{message}</p>
									</div>
								</div>
							</div>
						</div>
					</Transition>
				</div>
			</div>
		</>
	);
}
