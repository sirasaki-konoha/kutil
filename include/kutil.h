/*
	* MIT License

	* Copyright (c) 2025 木葉

	* Permission is hereby granted, free of charge, to any person obtaining a copy
	* of this software and associated documentation files (the "Software"), to deal
	* in the Software without restriction, including without limitation the rights
	* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	* copies of the Software, and to permit persons to whom the Software is
	* furnished to do so, subject to the following conditions:

	* The above copyright notice and this permission notice shall be included in all
	* copies or substantial portions of the Software.

	* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	* SOFTWARE.
*/


#ifndef _KONOHA_UTIL_H
#define _KONOHA_UTIL_H


/**
 * @brief  Creates a formatted string using a format specifier and variable arguments.
 *
 * This function formats a string according to the given printf-style format string
 * and variable arguments. It returns a dynamically allocated string that must be
 * freed by the caller using free().
 *
 * @param __format Format string (same syntax as printf)
 * @param ...      Arguments corresponding to the format specifiers
 * @return         A pointer to the newly allocated string (char*), or NULL on error.
 */
char *format_string(const char *restrict __format, ...);

/**
 * @brief Safe string duplication function
 * @param s String to duplicate
 * @return Pointer to duplidcate string, NULL on error
 */
char *safe_strdup(const char *s);

/**
 * @brief Joins an array of strings into a single string, inserting the specified
 * separator between each string.
 *
 * @param strings    A NULL-terminated array of strings to be joined.
 * @param separator  The string to insert between each pair of strings.
 * @return           A newly allocated string containing the joined result, or
 * NULL on allocation failure. The caller is responsible for freeing the
 * returned string.
 */
char *join_strings(char **strings, const char *separator);

/**
 * @brief Split a string on the ASCII space character (' ') and return a dynamically allocated array of tokens.
 *
 * @param input  The NUL-terminated string to split. Must not be NULL.
 *
 * @return A dynamically allocated, NULL-terminated array of dynamically allocated
 *         strings (tokens). The array can be freed with `free_str_array()`.
 *         Returns NULL on allocation failure.
 *
 * @note Behavior:
 *       - Only the ASCII space (0x20) is treated as a delimiter; tabs, newlines, etc. are not.
 *       - Consecutive spaces are treated as a single separator (no empty tokens).
 *       - Leading and trailing spaces are ignored.
 *       - The input string is not modified.
 *       - If `input` is an empty string, an empty array (first element is NULL) is returned.
 *
 * @see free_str_array()
 */
char **split_whitespace(const char *input);

/**
 * @brief Free a NULL-terminated array of dynamically allocated strings.
 *
 * @param arr  The NULL-terminated array to free. May be NULL.
 *
 * @note This function frees each string in the array and then frees the array itself.
 *       Passing NULL is safe and has no effect.
 *
 * @see split_whitespace()
 */
void free_str_array(char **arr);

#endif /* _KONOHA_UTIL_H */
