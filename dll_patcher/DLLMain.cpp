#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <intrin.h>
#include <wininet.h>
#include <filesystem>
#include <fstream>
#include <format>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "Urlmon.lib")

#include "bins.hpp"
#include "relocations.hpp"

void fix_imports(uint32_t mem)
{
	*reinterpret_cast<FARPROC*>(mem + 0x0) = GetProcAddress(LoadLibraryA("gdi32.dll"), "AddFontResourceA");
	*reinterpret_cast<FARPROC*>(mem + 0x8) = GetProcAddress(LoadLibraryA("imm32.dll"), "ImmSetCompositionWindow");
	*reinterpret_cast<FARPROC*>(mem + 0xC) = GetProcAddress(LoadLibraryA("imm32.dll"), "ImmReleaseContext");
	*reinterpret_cast<FARPROC*>(mem + 0x10) = GetProcAddress(LoadLibraryA("imm32.dll"), "ImmGetContext");
	*reinterpret_cast<FARPROC*>(mem + 0x18) = GetProcAddress(LoadLibraryA("kernel32.dll"), "ExitThread");
	*reinterpret_cast<FARPROC*>(mem + 0x1C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "VirtualQuery");
	*reinterpret_cast<FARPROC*>(mem + 0x20) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetModuleHandleA");
	*reinterpret_cast<FARPROC*>(mem + 0x24) = GetProcAddress(LoadLibraryA("kernel32.dll"), "WideCharToMultiByte");
	*reinterpret_cast<FARPROC*>(mem + 0x28) = GetProcAddress(LoadLibraryA("kernel32.dll"), "MultiByteToWideChar");
	*reinterpret_cast<FARPROC*>(mem + 0x2C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "Sleep");
	*reinterpret_cast<FARPROC*>(mem + 0x30) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GlobalAlloc");
	*reinterpret_cast<FARPROC*>(mem + 0x34) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GlobalFree");
	*reinterpret_cast<FARPROC*>(mem + 0x38) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GlobalLock");
	*reinterpret_cast<FARPROC*>(mem + 0x3C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GlobalUnlock");
	*reinterpret_cast<FARPROC*>(mem + 0x40) = GetProcAddress(LoadLibraryA("kernel32.dll"), "QueryPerformanceFrequency");
	*reinterpret_cast<FARPROC*>(mem + 0x44) = GetProcAddress(LoadLibraryA("kernel32.dll"), "QueryPerformanceCounter");
	*reinterpret_cast<FARPROC*>(mem + 0x48) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetPrivateProfileSectionA");
	*reinterpret_cast<FARPROC*>(mem + 0x4C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "WritePrivateProfileStringA");
	*reinterpret_cast<FARPROC*>(mem + 0x50) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CreateDirectoryA");
	*reinterpret_cast<FARPROC*>(mem + 0x54) = GetProcAddress(LoadLibraryA("kernel32.dll"), "EnterCriticalSection");
	*reinterpret_cast<FARPROC*>(mem + 0x58) = GetProcAddress(LoadLibraryA("kernel32.dll"), "LeaveCriticalSection");
	*reinterpret_cast<FARPROC*>(mem + 0x5C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "InitializeCriticalSectionAndSpinCount");
	*reinterpret_cast<FARPROC*>(mem + 0x60) = GetProcAddress(LoadLibraryA("kernel32.dll"), "DeleteCriticalSection");
	*reinterpret_cast<FARPROC*>(mem + 0x64) = GetProcAddress(LoadLibraryA("kernel32.dll"), "SetEvent");
	*reinterpret_cast<FARPROC*>(mem + 0x68) = GetProcAddress(LoadLibraryA("kernel32.dll"), "ResetEvent");
	*reinterpret_cast<FARPROC*>(mem + 0x6C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "WaitForSingleObjectEx");
	*reinterpret_cast<FARPROC*>(mem + 0x70) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CreateEventW");
	*reinterpret_cast<FARPROC*>(mem + 0x74) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetModuleHandleW");
	*reinterpret_cast<FARPROC*>(mem + 0x78) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetProcAddress");
	*reinterpret_cast<FARPROC*>(mem + 0x7C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "UnhandledExceptionFilter");
	*reinterpret_cast<FARPROC*>(mem + 0x80) = GetProcAddress(LoadLibraryA("kernel32.dll"), "SetUnhandledExceptionFilter");
	*reinterpret_cast<FARPROC*>(mem + 0x84) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetCurrentProcess");
	*reinterpret_cast<FARPROC*>(mem + 0x88) = GetProcAddress(LoadLibraryA("kernel32.dll"), "TerminateProcess");
	*reinterpret_cast<FARPROC*>(mem + 0x8C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "IsProcessorFeaturePresent");
	*reinterpret_cast<FARPROC*>(mem + 0x90) = GetProcAddress(LoadLibraryA("kernel32.dll"), "IsDebuggerPresent");
	*reinterpret_cast<FARPROC*>(mem + 0x94) = GetProcAddress(LoadLibraryA("kernel32.dll"), "FreeLibraryAndExitThread");
	*reinterpret_cast<FARPROC*>(mem + 0x98) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetCurrentProcessId");
	*reinterpret_cast<FARPROC*>(mem + 0x9C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetCurrentThreadId");
	*reinterpret_cast<FARPROC*>(mem + 0xA0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetSystemTimeAsFileTime");
	*reinterpret_cast<FARPROC*>(mem + 0xA4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "InitializeSListHead");
	*reinterpret_cast<FARPROC*>(mem + 0xA8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "InitializeCriticalSectionEx");
	*reinterpret_cast<FARPROC*>(mem + 0xAC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CreateThread");
	*reinterpret_cast<FARPROC*>(mem + 0xB0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CloseHandle");
	*reinterpret_cast<FARPROC*>(mem + 0xB4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "DisableThreadLibraryCalls");
	*reinterpret_cast<FARPROC*>(mem + 0xB8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "SetLastError");
	*reinterpret_cast<FARPROC*>(mem + 0xBC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "VirtualProtect");
	*reinterpret_cast<FARPROC*>(mem + 0xC0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "EncodePointer");
	*reinterpret_cast<FARPROC*>(mem + 0xC4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "DecodePointer");
	*reinterpret_cast<FARPROC*>(mem + 0xC8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetLocaleInfoEx");
	*reinterpret_cast<FARPROC*>(mem + 0xCC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "LCMapStringEx");
	*reinterpret_cast<FARPROC*>(mem + 0xD0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetStringTypeW");
	*reinterpret_cast<FARPROC*>(mem + 0xD4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CompareStringEx");
	*reinterpret_cast<FARPROC*>(mem + 0xD8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetCPInfo");
	*reinterpret_cast<FARPROC*>(mem + 0xDC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "RaiseException");
	*reinterpret_cast<FARPROC*>(mem + 0xE0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetLastError");
	*reinterpret_cast<FARPROC*>(mem + 0xE4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "HeapAlloc");
	*reinterpret_cast<FARPROC*>(mem + 0xE8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "HeapFree");
	*reinterpret_cast<FARPROC*>(mem + 0xEC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetProcessHeap");
	*reinterpret_cast<FARPROC*>(mem + 0xF0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "FreeLibrary");
	*reinterpret_cast<FARPROC*>(mem + 0xF4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "FlushInstructionCache");
	*reinterpret_cast<FARPROC*>(mem + 0xFC) = GetProcAddress(LoadLibraryA("shlwapi.dll"), "PathAppendA");
	*reinterpret_cast<FARPROC*>(mem + 0x104) = GetProcAddress(LoadLibraryA("user32.dll"), "CloseClipboard");
	*reinterpret_cast<FARPROC*>(mem + 0x108) = GetProcAddress(LoadLibraryA("user32.dll"), "OpenClipboard");
	*reinterpret_cast<FARPROC*>(mem + 0x10C) = GetProcAddress(LoadLibraryA("user32.dll"), "GetCursorPos");
	*reinterpret_cast<FARPROC*>(mem + 0x110) = GetProcAddress(LoadLibraryA("user32.dll"), "SetCursorPos");
	*reinterpret_cast<FARPROC*>(mem + 0x114) = GetProcAddress(LoadLibraryA("user32.dll"), "ReleaseCapture");
	*reinterpret_cast<FARPROC*>(mem + 0x118) = GetProcAddress(LoadLibraryA("user32.dll"), "GetClientRect");
	*reinterpret_cast<FARPROC*>(mem + 0x11C) = GetProcAddress(LoadLibraryA("user32.dll"), "SetCursor");
	*reinterpret_cast<FARPROC*>(mem + 0x120) = GetProcAddress(LoadLibraryA("user32.dll"), "SetCapture");
	*reinterpret_cast<FARPROC*>(mem + 0x124) = GetProcAddress(LoadLibraryA("user32.dll"), "GetForegroundWindow");
	*reinterpret_cast<FARPROC*>(mem + 0x128) = GetProcAddress(LoadLibraryA("user32.dll"), "EmptyClipboard");
	*reinterpret_cast<FARPROC*>(mem + 0x12C) = GetProcAddress(LoadLibraryA("user32.dll"), "FindWindowA");
	*reinterpret_cast<FARPROC*>(mem + 0x130) = GetProcAddress(LoadLibraryA("user32.dll"), "SetClipboardData");
	*reinterpret_cast<FARPROC*>(mem + 0x134) = GetProcAddress(LoadLibraryA("user32.dll"), "CallWindowProcA");
	*reinterpret_cast<FARPROC*>(mem + 0x138) = GetProcAddress(LoadLibraryA("user32.dll"), "IsChild");
	*reinterpret_cast<FARPROC*>(mem + 0x13C) = GetProcAddress(LoadLibraryA("user32.dll"), "GetFocus");
	*reinterpret_cast<FARPROC*>(mem + 0x140) = GetProcAddress(LoadLibraryA("user32.dll"), "ClientToScreen");
	*reinterpret_cast<FARPROC*>(mem + 0x144) = GetProcAddress(LoadLibraryA("user32.dll"), "GetKeyState");
	*reinterpret_cast<FARPROC*>(mem + 0x148) = GetProcAddress(LoadLibraryA("user32.dll"), "GetCapture");
	*reinterpret_cast<FARPROC*>(mem + 0x14C) = GetProcAddress(LoadLibraryA("user32.dll"), "ScreenToClient");
	*reinterpret_cast<FARPROC*>(mem + 0x150) = GetProcAddress(LoadLibraryA("user32.dll"), "LoadCursorA");
	*reinterpret_cast<FARPROC*>(mem + 0x154) = GetProcAddress(LoadLibraryA("user32.dll"), "SetWindowLongA");
	*reinterpret_cast<FARPROC*>(mem + 0x158) = GetProcAddress(LoadLibraryA("user32.dll"), "GetAsyncKeyState");
	*reinterpret_cast<FARPROC*>(mem + 0x15C) = GetProcAddress(LoadLibraryA("user32.dll"), "GetClipboardData");
	*reinterpret_cast<FARPROC*>(mem + 0x1C8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strtol");
	*reinterpret_cast<FARPROC*>(mem + 0x1CC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strtof");
	*reinterpret_cast<FARPROC*>(mem + 0x1D0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strtod");
	*reinterpret_cast<FARPROC*>(mem + 0x1D4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "atof");
	*reinterpret_cast<FARPROC*>(mem + 0x1D8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "atoi");
	*reinterpret_cast<FARPROC*>(mem + 0x1DC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_wtof");
	*reinterpret_cast<FARPROC*>(mem + 0x1E0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_wtoi");
	*reinterpret_cast<FARPROC*>(mem + 0x1E4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strtoul");
	*reinterpret_cast<FARPROC*>(mem + 0x1E8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_itoa");
	*reinterpret_cast<FARPROC*>(mem + 0x1F0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "getenv");
	*reinterpret_cast<FARPROC*>(mem + 0x1F8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "free");
	*reinterpret_cast<FARPROC*>(mem + 0x1FC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "calloc");
	*reinterpret_cast<FARPROC*>(mem + 0x200) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "realloc");
	*reinterpret_cast<FARPROC*>(mem + 0x204) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "malloc");
	*reinterpret_cast<FARPROC*>(mem + 0x208) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_callnewh");
	*reinterpret_cast<FARPROC*>(mem + 0x210) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_lock_locales");
	*reinterpret_cast<FARPROC*>(mem + 0x214) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "___lc_codepage_func");
	*reinterpret_cast<FARPROC*>(mem + 0x218) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "___lc_locale_name_func");
	*reinterpret_cast<FARPROC*>(mem + 0x21C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_unlock_locales");
	*reinterpret_cast<FARPROC*>(mem + 0x220) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "___lc_collate_cp_func");
	*reinterpret_cast<FARPROC*>(mem + 0x224) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__pctype_func");
	*reinterpret_cast<FARPROC*>(mem + 0x228) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "setlocale");
	*reinterpret_cast<FARPROC*>(mem + 0x22C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "localeconv");
	*reinterpret_cast<FARPROC*>(mem + 0x230) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "___mb_cur_max_func");
	*reinterpret_cast<FARPROC*>(mem + 0x238) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "frexp");
	*reinterpret_cast<FARPROC*>(mem + 0x23C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_sqrt_precise");
	*reinterpret_cast<FARPROC*>(mem + 0x240) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_sin_precise");
	*reinterpret_cast<FARPROC*>(mem + 0x244) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_pow_precise");
	*reinterpret_cast<FARPROC*>(mem + 0x248) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_log_precise");
	*reinterpret_cast<FARPROC*>(mem + 0x24C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_exp_precise");
	*reinterpret_cast<FARPROC*>(mem + 0x250) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_cos_precise");
	*reinterpret_cast<FARPROC*>(mem + 0x254) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fminf");
	*reinterpret_cast<FARPROC*>(mem + 0x258) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_CIpow");
	*reinterpret_cast<FARPROC*>(mem + 0x25C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "round");
	*reinterpret_cast<FARPROC*>(mem + 0x260) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fmaxf");
	*reinterpret_cast<FARPROC*>(mem + 0x264) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "floor");
	*reinterpret_cast<FARPROC*>(mem + 0x268) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "remainderf");
	*reinterpret_cast<FARPROC*>(mem + 0x26C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "ldexp");
	*reinterpret_cast<FARPROC*>(mem + 0x270) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_CIatan2");
	*reinterpret_cast<FARPROC*>(mem + 0x274) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_atan_precise");
	*reinterpret_cast<FARPROC*>(mem + 0x278) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_CIfmod");
	*reinterpret_cast<FARPROC*>(mem + 0x27C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "ceil");
	*reinterpret_cast<FARPROC*>(mem + 0x280) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_asin_precise");
	*reinterpret_cast<FARPROC*>(mem + 0x284) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_tan_precise");
	*reinterpret_cast<FARPROC*>(mem + 0x288) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_fdclass");
	*reinterpret_cast<FARPROC*>(mem + 0x28C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "roundf");
	*reinterpret_cast<FARPROC*>(mem + 0x294) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_initialize_onexit_table");
	*reinterpret_cast<FARPROC*>(mem + 0x298) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_seh_filter_dll");
	*reinterpret_cast<FARPROC*>(mem + 0x29C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_invalid_parameter_noinfo_noreturn");
	*reinterpret_cast<FARPROC*>(mem + 0x2A0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_configure_narrow_argv");
	*reinterpret_cast<FARPROC*>(mem + 0x2A4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_initialize_narrow_environment");
	*reinterpret_cast<FARPROC*>(mem + 0x2A8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_errno");
	*reinterpret_cast<FARPROC*>(mem + 0x2AC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_register_onexit_function");
	*reinterpret_cast<FARPROC*>(mem + 0x2B0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_execute_onexit_table");
	*reinterpret_cast<FARPROC*>(mem + 0x2B4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "abort");
	*reinterpret_cast<FARPROC*>(mem + 0x2B8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_crt_atexit");
	*reinterpret_cast<FARPROC*>(mem + 0x2BC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_cexit");
	*reinterpret_cast<FARPROC*>(mem + 0x2C0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_initterm");
	*reinterpret_cast<FARPROC*>(mem + 0x2C4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "terminate");
	*reinterpret_cast<FARPROC*>(mem + 0x2C8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_initterm_e");
	*reinterpret_cast<FARPROC*>(mem + 0x2D0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_wfopen");
	*reinterpret_cast<FARPROC*>(mem + 0x2D4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fread");
	*reinterpret_cast<FARPROC*>(mem + 0x2D8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__stdio_common_vfprintf");
	*reinterpret_cast<FARPROC*>(mem + 0x2DC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fopen");
	*reinterpret_cast<FARPROC*>(mem + 0x2E0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fclose");
	*reinterpret_cast<FARPROC*>(mem + 0x2E4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fflush");
	*reinterpret_cast<FARPROC*>(mem + 0x2E8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "ftell");
	*reinterpret_cast<FARPROC*>(mem + 0x2EC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__stdio_common_vsprintf");
	*reinterpret_cast<FARPROC*>(mem + 0x2F0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__stdio_common_vsprintf_s");
	*reinterpret_cast<FARPROC*>(mem + 0x2F4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fwrite");
	*reinterpret_cast<FARPROC*>(mem + 0x2F8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fseek");
	*reinterpret_cast<FARPROC*>(mem + 0x2FC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__stdio_common_vsscanf");
	*reinterpret_cast<FARPROC*>(mem + 0x304) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strncpy_s");
	*reinterpret_cast<FARPROC*>(mem + 0x308) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strtok");
	*reinterpret_cast<FARPROC*>(mem + 0x30C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strcpy_s");
	*reinterpret_cast<FARPROC*>(mem + 0x310) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_mbsdup");
	*reinterpret_cast<FARPROC*>(mem + 0x314) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strcat");
	*reinterpret_cast<FARPROC*>(mem + 0x318) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strcmp");
	*reinterpret_cast<FARPROC*>(mem + 0x31C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strlen");
	*reinterpret_cast<FARPROC*>(mem + 0x320) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strncmp");
	*reinterpret_cast<FARPROC*>(mem + 0x324) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strcpy");
	*reinterpret_cast<FARPROC*>(mem + 0x328) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "isupper");
	*reinterpret_cast<FARPROC*>(mem + 0x32C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_wcsdup");
	*reinterpret_cast<FARPROC*>(mem + 0x330) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "islower");
	*reinterpret_cast<FARPROC*>(mem + 0x334) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__strncnt");
	*reinterpret_cast<FARPROC*>(mem + 0x338) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "toupper");
	*reinterpret_cast<FARPROC*>(mem + 0x33C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strcspn");
	*reinterpret_cast<FARPROC*>(mem + 0x340) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_stricmp");
	*reinterpret_cast<FARPROC*>(mem + 0x344) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "tolower");
	*reinterpret_cast<FARPROC*>(mem + 0x348) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "isspace");
	*reinterpret_cast<FARPROC*>(mem + 0x34C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "isxdigit");
	*reinterpret_cast<FARPROC*>(mem + 0x350) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "wcsnlen");
	*reinterpret_cast<FARPROC*>(mem + 0x354) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strcat_s");
	*reinterpret_cast<FARPROC*>(mem + 0x358) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strncpy");
	*reinterpret_cast<FARPROC*>(mem + 0x360) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_Getdays");
	*reinterpret_cast<FARPROC*>(mem + 0x364) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_W_Getmonths");
	*reinterpret_cast<FARPROC*>(mem + 0x368) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_Strftime");
	*reinterpret_cast<FARPROC*>(mem + 0x36C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_Gettnames");
	*reinterpret_cast<FARPROC*>(mem + 0x370) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_Wcsftime");
	*reinterpret_cast<FARPROC*>(mem + 0x374) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_W_Gettnames");
	*reinterpret_cast<FARPROC*>(mem + 0x378) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_W_Getdays");
	*reinterpret_cast<FARPROC*>(mem + 0x37C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_Getmonths");
	*reinterpret_cast<FARPROC*>(mem + 0x384) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "qsort");
	*reinterpret_cast<FARPROC*>(mem + 0x388) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "rand");
	*reinterpret_cast<FARPROC*>(mem + 0x390) = GetProcAddress(LoadLibraryA("urlmon.dll"), "URLDownloadToFileA");
}

void fix_relocations(uint32_t cheat_mem, uint32_t stub_mem)
{
	uint32_t delta = cheat_mem - 0x36DA0000;

	for (uint32_t i = 0; i < cheat_relocations.size(); i++) //relocate the cheat
	{
		*reinterpret_cast<uint32_t*>(cheat_mem + cheat_relocations[i]) += delta;
	}

	delta = stub_mem - 0x370D0000;

	for (uint32_t i = 0; i < stub_relocations.size(); i++) //relocate the stub
	{
		*reinterpret_cast<uint32_t*>(stub_mem + stub_relocations[i]) += delta;
	}
}

decltype(&URLDownloadToFileA) oURLDownloadToFileA;

HRESULT __stdcall hooked_URLDownloadToFileA(
	LPUNKNOWN            pCaller,
	LPCTSTR              szURL,
	LPCTSTR              szFileName,
	_Reserved_ DWORD                dwReserved,
	LPBINDSTATUSCALLBACK lpfnCB
)
{
	if (strstr(szFileName, "iblis")) //if text contains iblis write the font to disk instead of using the internet.
	{
		std::cout << "Writing font to disk..." << std::endl;
		std::ofstream file("iblis\\tmp.ttf", std::ios::out | std::ios::binary);
		file.write(reinterpret_cast<char*>(&font[0]), sizeof(font));
		file.close();
		return S_OK;
	}
	return oURLDownloadToFileA(pCaller, szURL, szFileName, dwReserved, lpfnCB);
}

void main()
{
	void* cheat_mem = VirtualAlloc(0, sizeof(hack_bin), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE); //allocate at random allocation for cheat
	if (!cheat_mem)
	{
		MessageBoxA(0, "Failed to allocate memory", "ERROR", MB_OK);
		exit(0);
		return;
	}

	void* stub_mem = VirtualAlloc(0, sizeof(hack_bin), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (!stub_mem)
	{
		MessageBoxA(0, "Failed to allocate memory2", "ERROR", MB_OK);
		exit(0);
		return;
	}

	std::cout << std::format("Cheat allocated @ {}\nStub allocated @ {}", cheat_mem, stub_mem) << std::endl;

	memcpy(cheat_mem, hack_bin, sizeof(hack_bin));
	memcpy(stub_mem, stub_bin, sizeof(stub_bin));

	std::cout << "Waiting for serverbrowser.dll" << std::endl;;

	while (!GetModuleHandleA("serverbrowser.dll"))
	{
		Sleep(100);
	}
	std::cout << "Fixing relocations" << std::endl;

	fix_relocations(reinterpret_cast<uint32_t>(cheat_mem), reinterpret_cast<uint32_t>(stub_mem));

	std::cout << "Fixed relocations" << std::endl;

	std::cout << "Fixing imports" << std::endl;

	fix_imports(reinterpret_cast<uint32_t>(cheat_mem) + 0x226000); //0x226000 RVA

	std::cout << "Fixed imports" << std::endl;

	std::cout << "Setting up hook" << std::endl;

	if (MH_Initialize() != MH_OK)
	{
		std::cout << "Failed to init minhook" << std::endl;
		return;
	}

	if (MH_CreateHook(&URLDownloadToFileA, hooked_URLDownloadToFileA, reinterpret_cast<void**>(&oURLDownloadToFileA)) != MH_OK)
	{
		std::cout << "Failed to create hook at URLDownloadToFileA" << std::endl;
		return;
	}

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
	{
		std::cout << "Failed to enable hook" << std::endl;
		return;
	}

	std::cout << "Set up hook" << std::endl;

	std::cout << std::format("Calling DLLMain @ {}", reinterpret_cast<void*>(reinterpret_cast<uint32_t>(cheat_mem) + 0x159A16)) << std::endl;

	__asm
	{
		push 0
		push 1
		push cheat_mem
		mov eax, cheat_mem
		add eax, 0x159A16 //0x159A16 RVA
		call eax
	}

	std::cout << "Called DLLMain" << std::endl;
	std::cout << "Owned by PinkKing#8199" << std::endl;
}

bool __stdcall DllMain(HANDLE hinstDLL, uint32_t fdwReason, void* lpReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
		AllocConsole();
		SetConsoleTitleA("iblis.club");
		freopen("CONOUT$", "w", stdout);
		CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(main), 0, 0, 0);
	}
    return true;
}