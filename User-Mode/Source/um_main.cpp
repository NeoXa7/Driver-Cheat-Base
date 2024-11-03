#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <Driver/Process.hpp>
#include <Driver/UM_Driver.hpp>

#define Success 0;
#define Failed 1;

int main() {
    if (Notepad::ProcID <= 0)
    {
        std::cout << " [+] Failed to find designated Process (notepad.exe)\n";
        return Failed;
        std::cin.get();
    }

    Driver::driver_handle = CreateFile(L"\\\\.\\Synapse", GENERIC_READ, 0, nullptr, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, nullptr);

    if (Driver::driver_handle == INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed to create our driver handle\n";
        std::cin.get();
        return Failed;
    }

    if (Driver::attach_to_process(Driver::driver_handle, Notepad::ProcID) == true)
    {
        std::cout << "Attachment Successfull\n";
        // Cheat Logic Goes Inside this Function;
    }

    CloseHandle(Driver::driver_handle);
    std::cin.get();
    return 0;
}
