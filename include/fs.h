/*****************************************************************************
*
*  PROJECT:     CIV5: Scripthook
*  LICENSE:     See LICENSE in the top level directory
*  PURPOSE:     Filesystem compatibility wrapper
*
*****************************************************************************/
#pragma once

#include <filesystem>

#ifdef _WIN32
	namespace fs = std::experimental::filesystem;
#endif
