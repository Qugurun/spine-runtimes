/******************************************************************************
 * Spine Runtimes Software License v2.5
 *
 * Copyright (c) 2013-2016, Esoteric Software
 * All rights reserved.
 *
 * You are granted a perpetual, non-exclusive, non-sublicensable, and
 * non-transferable license to use, install, execute, and perform the Spine
 * Runtimes software and derivative works solely for personal or internal
 * use. Without the written permission of Esoteric Software (see Section 2 of
 * the Spine Software License Agreement), you may not (a) modify, translate,
 * adapt, or develop new applications using the Spine Runtimes or otherwise
 * create derivative works or improvements of the Spine Runtimes or (b) remove,
 * delete, alter, or obscure any trademarks or any copyright, trademark, patent,
 * or other intellectual property or proprietary rights notices on or in the
 * Software, including any copy thereof. Redistributions in binary or source
 * form must include this license and terms.
 *
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, BUSINESS INTERRUPTION, OR LOSS OF
 * USE, DATA, OR PROFITS) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/


#ifndef SPINE_TESTHARNESS_H
#define SPINE_TESTHARNESS_H

#include <spine/Extension.h>
#include <vector>

namespace Spine {
	struct Allocation {
		void* address;
		size_t size;
		const char* fileName;
		int line;

		Allocation() : address(NULL), size(0), fileName(NULL), line(0) {
		}

		Allocation(void* a, size_t s, const char* f, int l) : address(a), size(s), fileName(f), line(l) {
		}
	};

	class TestSpineExtension: public DefaultSpineExtension {
	public:
		void reportLeaks ();
		void clearAllocations();

	protected:
		virtual void* _alloc(size_t size, const char* file, int line);

		virtual void* _calloc(size_t size, const char* file, int line);

		virtual void* _realloc(void* ptr, size_t size, const char* file, int line);

		virtual void _free(void* mem, const char* file, int line);

	private:
		std::vector<Allocation> allocated;
	};
}


#endif //SPINE_TESTHARNESS_H