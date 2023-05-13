import { useRouter } from "next/router";
import { useState, useEffect, useLayoutEffect, useContext } from "react";
import { ToastContainer, toast } from "react-toastify";
import "react-toastify/dist/ReactToastify.css";
import NavBar from "./NavBar";
import Loading from "./ui/Loading";
import { SocketContext } from "@/lib/socketContext";
import FriendNotification from "./ui/FriendNotification";
import { NotifyProvider } from "@/lib/notifyContext";
import GlobalNotification from "@/components/ui/GlobalNotification";
import ChatNotification from "./ui/ChatNotification";
import GameNotification from "./ui/GameNotification";
import { useUsersDispatch, useUsersState, getUser } from "@/lib/userContext";

export const Notifications = () => {
	return (
		<>
			<GlobalNotification />
			<ChatNotification />
			<FriendNotification />
			<GameNotification />
		</>
	);
};

export default function Layout({
	pageProps,
	children,
}: {
	pageProps?: any;
	children: React.ReactNode;
}) {
	const router = useRouter();
	const [userData, setuserData] = useState<any>([]);
	const [isNavView, setisNavView] = useState(true);
	const state = useUsersState();
	const dispatch = useUsersDispatch();

	useEffect(() => {
		getUser(dispatch);
	}, [dispatch]);

	const { data: user, loading, error } = state.user;

	useEffect(() => {
		if (router.asPath.startsWith("/lobby/game")) {
			setisNavView(false);
		}
		else {
			setisNavView(true);
		}
		if (error) {
			router.push("/");
		}
	}, [error, router]);

	// 소켓 연결
	const { friendSocket: socket } = useContext(SocketContext);
	useEffect(() => {
		function changeUserStatus(data: any) {
			let copy = [...userData];
			const alteredCopy = copy.map((user) => {
				if (user.id === data.id) {
					return data;
				} else {
					return user;
				}
			});
			setuserData(alteredCopy);
		}
		function RenewFriend(data: any) {
			let copy = [...userData];
			let alteredCopy = copy.filter((user) => {
				return user.id !== data.id;
			});
			if (copy.length === alteredCopy.length) {
				alteredCopy.push(data);
			}
			setuserData(alteredCopy);
		}

		if (socket) {
			socket.on("friendList", (data) => {
				setuserData(data);
			});
			socket.on("friendActive", (data) => {
				changeUserStatus(data);
			});
			socket.on("friendRenew", (data) => {
				RenewFriend(data);
			});
		}

		return () => {
			if (socket) {
				socket.off("friendList");
				socket.off("friendActive");
				socket.off("friendRenew");
			}
		}
	}, [socket, userData]);

	return (
		<>
			{loading ? (
				<>
					<Loading />
				</>
			) : (
				<NotifyProvider>
					<Notifications />
					<ToastContainer
					position="top-right"
					autoClose={5000}
					hideProgressBar={false}
					newestOnTop={false}
					closeOnClick
					rtl={false}
					pauseOnFocusLoss
					draggable
					pauseOnHover
					theme="dark"
					/>
					<div className="bg-zinc-800 text-white lg:flex">
						{isNavView && <NavBar userData={userData} />}
						<div className="relative flex w-full flex-1 px-8 py-6">
							{pageProps}
							{children}
						</div>
					</div>
				</NotifyProvider>
			)}
		</>
	);
}
