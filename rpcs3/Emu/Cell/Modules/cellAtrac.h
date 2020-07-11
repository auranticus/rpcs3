#pragma once

#include "Emu/Memory/vm_ptr.h"

// Return Codes
enum
{
	CELL_ATRAC_ERROR_API_FAIL                    = 0x80610301,
	CELL_ATRAC_ERROR_READSIZE_OVER_BUFFER        = 0x80610311,
	CELL_ATRAC_ERROR_UNKNOWN_FORMAT              = 0x80610312,
	CELL_ATRAC_ERROR_READSIZE_IS_TOO_SMALL       = 0x80610313,
	CELL_ATRAC_ERROR_ILLEGAL_SAMPLING_RATE       = 0x80610314,
	CELL_ATRAC_ERROR_ILLEGAL_DATA                = 0x80610315,
	CELL_ATRAC_ERROR_NO_DECODER                  = 0x80610321,
	CELL_ATRAC_ERROR_UNSET_DATA                  = 0x80610322,
	CELL_ATRAC_ERROR_DECODER_WAS_CREATED         = 0x80610323,
	CELL_ATRAC_ERROR_ALLDATA_WAS_DECODED         = 0x80610331,
	CELL_ATRAC_ERROR_NODATA_IN_BUFFER            = 0x80610332,
	CELL_ATRAC_ERROR_NOT_ALIGNED_OUT_BUFFER      = 0x80610333,
	CELL_ATRAC_ERROR_NEED_SECOND_BUFFER          = 0x80610334,
	CELL_ATRAC_ERROR_ALLDATA_IS_ONMEMORY         = 0x80610341,
	CELL_ATRAC_ERROR_ADD_DATA_IS_TOO_BIG         = 0x80610342,
	CELL_ATRAC_ERROR_NONEED_SECOND_BUFFER        = 0x80610351,
	CELL_ATRAC_ERROR_UNSET_LOOP_NUM              = 0x80610361,
	CELL_ATRAC_ERROR_ILLEGAL_SAMPLE              = 0x80610371,
	CELL_ATRAC_ERROR_ILLEGAL_RESET_BYTE          = 0x80610372,
	CELL_ATRAC_ERROR_ILLEGAL_PPU_THREAD_PRIORITY = 0x80610381,
	CELL_ATRAC_ERROR_ILLEGAL_SPU_THREAD_PRIORITY = 0x80610382,
};

// Remain Frame
enum : s32
{
	CELL_ATRAC_ALLDATA_IS_ON_MEMORY             = -1,
	CELL_ATRAC_NONLOOP_STREAM_DATA_IS_ON_MEMORY = -2,
	CELL_ATRAC_LOOP_STREAM_DATA_IS_ON_MEMORY    = -3,
};

struct alignas(8) CellAtracHandle
{
	vm::ptr<u8> pucWorkMem;
	// ...
};

CHECK_MAX_SIZE(CellAtracHandle, 512);

struct CellAtracBufferInfo
{
	vm::ptr<u8> pucWriteAddr;
	be_t<u32> uiWritableByte;
	be_t<u32> uiMinWriteByte;
	be_t<u32> uiReadPosition;
};

struct CellAtracExtRes
{
	vm::ptr<struct CellSpurs> pSpurs;
	u8 priority[8];
};
