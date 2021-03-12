#include "cmdlineArgs.h"

void print(std::string text) {
	std::cout << text << std::endl;
}

void cmdlineHelp() {
	print("--- Shadow Browser Help ---");
	print("");
	print("--help   | -h : Show this help out thingie");
	print("--detach | -d : Detach the Shadow Browser process from the running tty");
	exit(0);
}

void cmdlineDetach() {
	print("Detaching...");

	exit(0);
}
