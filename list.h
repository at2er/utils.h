/* Thanks for wayland-util[1]
 *
 * Copyright © 2008-2011 Kristian Høgsberg
 * Copyright © 2011 Intel Corporation
 * Copyright © 2026 at2er
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * [1] wayland-util:
 *     https://cgit.freedesktop.org/wayland/wayland/tree/src/wayland-util.c
 * */
#ifndef UTILSH_LIST_H
#define UTILSH_LIST_H
#include <stddef.h>

struct utilsh_list {
	struct utilsh_list *prv;
	struct utilsh_list *nex;
};

#define utilsh_list_container_of(PTR, STRUCT, MEMBER) \
	(STRUCT*)((char*)(PTR) - offsetof(STRUCT, MEMBER))

#define utilsh_list_for_each(TYPE, CUR, BEG, NEX, LINK) \
	for (TYPE *CUR = utilsh_list_container_of((BEG)->prv, TYPE, LINK), \
			*NEX = utilsh_list_container_of((CUR)->LINK.prv, TYPE, LINK); \
			&CUR->LINK != (BEG); \
			CUR = NEX, \
			NEX = utilsh_list_container_of((CUR)->LINK.prv, TYPE, LINK))

void utilsh_list_init(struct utilsh_list *list);
void utilsh_list_insert(struct utilsh_list *list, struct utilsh_list *elem);

#endif

#ifdef UTILSH_LIST_IMPL

void
utilsh_list_init(struct utilsh_list *list)
{
	list->prv = list;
	list->nex = list;
}

void
utilsh_list_insert(struct utilsh_list *list, struct utilsh_list *elem)
{
	elem->prv = list;
	elem->nex = list->nex;
	list->nex = elem;
	elem->nex->prv = elem;
}

#endif /* UTILSH_LIST_IMPL */
