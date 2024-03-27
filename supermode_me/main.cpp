#include "rwptm.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Please start supermode.exe instead of this application\n";
		system("pause");
		return -1;
	}
	else if (strcmp(argv[1], "SUPERMODE") != 0)
	{
		std::cout << "Please start supermode.exe instead of this application\n";
		system("pause");
		return -1;
	}

	std::cout << "Starting...\n";

	while (!supermode_comm::load())
	{
		std::cout << "retrying to load...\n";
		Sleep(1000);
	}
	
	std::cout << "Open the game...\n";
	system("pause");

	rwptm::init("Taskmgr.exe", "supermode_me.exe");

	system("pause");

	while (true)
	{
		const auto rpm_time2 = [&]() -> float
			{
				auto time_now = std::chrono::high_resolution_clock::now();
				for (auto x = 0ull; x < 0x100000; x++)
				{

					auto value = rwptm::read_virtual_memory<std::uintptr_t>(rwptm::target_base + x);
					if (!value)
						continue;
				}
				auto time_span =
					std::chrono::duration_cast<std::chrono::duration< float>>(std::chrono::high_resolution_clock::now() - time_now);
				return time_span.count();
			};
		std::printf(" [read(0x100,000)] -> %fs\n", rpm_time2());


		std::printf("we did it hyper boo");
		Sleep(100);
	}



	system("pause");

	return 1;
}