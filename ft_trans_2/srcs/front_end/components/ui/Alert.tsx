import { XCircleIcon } from "@heroicons/react/20/solid";

export default function Alert({
	title,
	messages,
}: {
	title: string;
	messages: string[];
}) {
	return (
		<div className="w-full max-w-lg rounded-md bg-red-500 p-4">
			<div className="flex">
				<div className="flex-shrink-0">
					<XCircleIcon className="h-5 w-5 text-white" aria-hidden="true" />
				</div>
				<div className="ml-3">
					<h3 className="text-sm font-medium text-white">{title}</h3>
					<div className="mt-2 text-sm text-zinc-100">
						<ul role="list" className="list-disc space-y-1 pl-5">
							{messages.map((message, index) => (
								<li key={index}>{message}</li>
							))}
						</ul>
					</div>
				</div>
			</div>
		</div>
	);
}
