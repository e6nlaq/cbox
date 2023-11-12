/****************************************************************

	script/fetch.ts

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

async function main(url: string): Promise<void> {
	const ret: string = await (await fetch(url)).text();
	console.log(ret);
}

if (process.argv.length !== 3) {
	console.error("Error: URL must be specified in the command line argument.");
	process.exit(1);
}

main(process.argv[2]);
