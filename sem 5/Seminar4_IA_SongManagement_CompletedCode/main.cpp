#include "ui.h"
#include <crtdbg.h>
void start_app() {
	RepositoryFile repo{ "songs.txt" };
	Service srv{ repo };
	UI ui{ srv };
	ui.run();
}
int main() {
	/*auto m = MediaItem("1", "1", "1","1:2");
	return 0;*/
	//_CrtSetBreakAlloc(469); // will break when block 469 is allocated
	start_app();
	_CrtDumpMemoryLeaks();
	return 0;

}