#include "supermode.h"

int main( )
{
	remove("C:\\indices.json");
	std::printf( "\n [vmx] -> welcome.\n" );
	//HANDLE h = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)start_thread, NULL, NULL, NULL);
	//if (h)
	//	CloseHandle(h);

	auto target = m_physical.get( )->get_process_base( "access.exe" );
	if ( !target ) {
		std::printf( " [vmx] -> failed to get target.\n" );
		std::cin.get( );
	}

	supermode::insert_pte();
	supermode::insert_pfn();
	//supermode::insert_target( m_physical.get( )->cr3 );

	supermode::save_indices_for_target();

	//std::cout << "unloading wnbios...\n";
	//supermode::wnbios.unload_driver();

	std::printf( "\n [access] -> pte-pfn manipulation invoked.\n" );

	std::cin.get( );
	return 1;
}

/*
	uintptr_t target_base = m_physical->get_process_base( "Taskmgr.exe" );
	std::cout << " base -> " << target_base << std::endl;

	uintptr_t target_cr3 = m_physical->find_dtb_from_base(target_base);
	std::cout << std::hex << target_cr3 << std::endl;
*/