/*
 * ProFTPD - FTP server daemon
 * Copyright (c) 2006-2008 The ProFTPD Project team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307, USA.
 *
 * As a special exemption, The ProFTPD Project team and other respective
 * copyright holders give permission to link this program with OpenSSL, and
 * distribute the resulting executable, without including the source code for
 * OpenSSL in the source distribution.
 */

/* UTF8/charset encoding/decoding
 * $Id: encode.h,v 1.1 2008-04-03 01:34:18 castaglia Exp $
 */

#ifndef PR_ENCODE_H
#define PR_ENCODE_H

/* Translates the `in' string into the local charset using the configured
 * encoding and returns the result.  NULL is returned if there was an error.
 */
char *pr_decode_str(pool *p, const char *in, size_t inlen, size_t *outlen);

/* Translates the `in' string from the local charset using the configured
 * encoding and returns the result.  NULL is returned if there was an error.
 */
char *pr_encode_str(pool *p, const char *in, size_t inlen, size_t *outlen);

/* Disables runtime use of encoding (assuming NLS is supported). */
void pr_encode_disable_encoding(void);

/* Enables runtime use of encoding using the specified character set (assuming
 * NLS is supported).  Zero is returned on success, -1 if there was an
 * issue either with the provided character set, or with the handling of
 * that set.
 */
int pr_encode_enable_encoding(const char *encoding);

/* Returns string describing the current local charset being used. */
const char *pr_encode_get_charset(void);

/* Returns string describing the current character set (or UTF8) encoding
 * being used.  NULL is returned if no encoding is currently in effect.
 */
const char *pr_encode_get_encoding(void);

/* Convenience function which returns TRUE if the given encoding is UTF8,
 * FALSE otherwise.  (There are multiple different strings for denoting
 * UTF8, and callers should not need to have to know about those different
 * formulations.)
 *
 * Note that -1 will be returned if there was an error (e.g. NULL arguments).
 */
int pr_encode_is_utf8(const char *codeset);

/* Change the local charset AND encoding being used. */
int pr_encode_set_charset_encoding(const char *charset, const char *encoding);

/* Internal use only. */
int encode_init(void);
int encode_free(void);

#endif /* PR_ENCODE_H */
