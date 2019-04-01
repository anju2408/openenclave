// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

/*
 *  This file is auto generated by oeedger8r. DO NOT EDIT.
 */
#include "oe_u.h"
#include <openenclave/edger8r/host.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

OE_EXTERNC_BEGIN

/* Wrappers for ecalls */

oe_result_t public_root_ecall(oe_enclave_t* enclave)
{
    oe_result_t _result = OE_FAILURE;

    /* Marshalling struct */
    public_root_ecall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;

    /* Marshalling buffer and sizes */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(public_root_ecall_args_t));

    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(public_root_ecall_args_t));

    /* Allocate marshalling buffer */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);

    _buffer = (uint8_t*)malloc(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }

    /* Serialize buffer inputs (in and in-out parameters) */
    *(uint8_t**)&_pargs_in = _input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));

    /* Copy args structure (now filled) to input buffer */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    /* Call enclave function */
    if ((_result = oe_call_enclave_function(
             enclave,
             fcn_id_public_root_ecall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Set up output arg struct pointer */
    *(uint8_t**)&_pargs_out = _output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));

    /* Check if the call succeeded */
    if ((_result = _pargs_out->_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters */

    _result = OE_OK;
done:
    if (_buffer)
        free(_buffer);
    return _result;
}

/* ocall functions */

void ocall_oe_hostfs_open(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_open_args_t* pargs_in = (oe_hostfs_open_args_t*)input_buffer;
    oe_hostfs_open_args_t* pargs_out = (oe_hostfs_open_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(pathname, pargs_in->pathname_len * sizeof(char));

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_open(
        (const char*)pargs_in->pathname,
        pargs_in->flags,
        pargs_in->mode,
        pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_read(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_read_args_t* pargs_in = (oe_hostfs_read_args_t*)input_buffer;
    oe_hostfs_read_args_t* pargs_out = (oe_hostfs_read_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(buf, pargs_in->count);
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_read(
        pargs_in->fd, pargs_in->buf, pargs_in->count, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_write(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_write_args_t* pargs_in = (oe_hostfs_write_args_t*)input_buffer;
    oe_hostfs_write_args_t* pargs_out = (oe_hostfs_write_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(buf, pargs_in->count);

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_write(
        pargs_in->fd,
        (const void*)pargs_in->buf,
        pargs_in->count,
        pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_lseek(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_lseek_args_t* pargs_in = (oe_hostfs_lseek_args_t*)input_buffer;
    oe_hostfs_lseek_args_t* pargs_out = (oe_hostfs_lseek_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_lseek(
        pargs_in->fd, pargs_in->offset, pargs_in->whence, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_close(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_close_args_t* pargs_in = (oe_hostfs_close_args_t*)input_buffer;
    oe_hostfs_close_args_t* pargs_out = (oe_hostfs_close_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_close(pargs_in->fd, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_dup(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_dup_args_t* pargs_in = (oe_hostfs_dup_args_t*)input_buffer;
    oe_hostfs_dup_args_t* pargs_out = (oe_hostfs_dup_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_dup(pargs_in->oldfd, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_opendir(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_opendir_args_t* pargs_in =
        (oe_hostfs_opendir_args_t*)input_buffer;
    oe_hostfs_opendir_args_t* pargs_out =
        (oe_hostfs_opendir_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(name, pargs_in->name_len * sizeof(char));

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval =
        oe_hostfs_opendir((const char*)pargs_in->name, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_readdir(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_readdir_args_t* pargs_in =
        (oe_hostfs_readdir_args_t*)input_buffer;
    oe_hostfs_readdir_args_t* pargs_out =
        (oe_hostfs_readdir_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(ent, (1 * sizeof(struct oe_hostfs_dirent_struct)));
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval =
        oe_hostfs_readdir(pargs_in->dirp, pargs_in->ent, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_rewinddir(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_rewinddir_args_t* pargs_in =
        (oe_hostfs_rewinddir_args_t*)input_buffer;
    oe_hostfs_rewinddir_args_t* pargs_out =
        (oe_hostfs_rewinddir_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */

    /* Call user function */
    oe_hostfs_rewinddir(pargs_in->dirp);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_closedir(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_closedir_args_t* pargs_in =
        (oe_hostfs_closedir_args_t*)input_buffer;
    oe_hostfs_closedir_args_t* pargs_out =
        (oe_hostfs_closedir_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_closedir(pargs_in->dirp, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_stat(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_stat_args_t* pargs_in = (oe_hostfs_stat_args_t*)input_buffer;
    oe_hostfs_stat_args_t* pargs_out = (oe_hostfs_stat_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(pathname, pargs_in->pathname_len * sizeof(char));

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(buf, (1 * sizeof(struct oe_hostfs_stat_struct)));
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_stat(
        (const char*)pargs_in->pathname, pargs_in->buf, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_access(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_access_args_t* pargs_in = (oe_hostfs_access_args_t*)input_buffer;
    oe_hostfs_access_args_t* pargs_out =
        (oe_hostfs_access_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(pathname, pargs_in->pathname_len * sizeof(char));

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_access(
        (const char*)pargs_in->pathname, pargs_in->mode, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_link(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_link_args_t* pargs_in = (oe_hostfs_link_args_t*)input_buffer;
    oe_hostfs_link_args_t* pargs_out = (oe_hostfs_link_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(oldpath, pargs_in->oldpath_len * sizeof(char));
    OE_SET_IN_POINTER(newpath, pargs_in->newpath_len * sizeof(char));

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_link(
        (const char*)pargs_in->oldpath,
        (const char*)pargs_in->newpath,
        pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_unlink(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_unlink_args_t* pargs_in = (oe_hostfs_unlink_args_t*)input_buffer;
    oe_hostfs_unlink_args_t* pargs_out =
        (oe_hostfs_unlink_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(pathname, pargs_in->pathname_len * sizeof(char));

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval =
        oe_hostfs_unlink((const char*)pargs_in->pathname, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_rename(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_rename_args_t* pargs_in = (oe_hostfs_rename_args_t*)input_buffer;
    oe_hostfs_rename_args_t* pargs_out =
        (oe_hostfs_rename_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(oldpath, pargs_in->oldpath_len * sizeof(char));
    OE_SET_IN_POINTER(newpath, pargs_in->newpath_len * sizeof(char));

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_rename(
        (const char*)pargs_in->oldpath,
        (const char*)pargs_in->newpath,
        pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_truncate(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_truncate_args_t* pargs_in =
        (oe_hostfs_truncate_args_t*)input_buffer;
    oe_hostfs_truncate_args_t* pargs_out =
        (oe_hostfs_truncate_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(path, pargs_in->path_len * sizeof(char));

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_truncate(
        (const char*)pargs_in->path, pargs_in->length, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_mkdir(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_mkdir_args_t* pargs_in = (oe_hostfs_mkdir_args_t*)input_buffer;
    oe_hostfs_mkdir_args_t* pargs_out = (oe_hostfs_mkdir_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(pathname, pargs_in->pathname_len * sizeof(char));

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval = oe_hostfs_mkdir(
        (const char*)pargs_in->pathname, pargs_in->mode, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

void ocall_oe_hostfs_rmdir(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;
    OE_UNUSED(input_buffer_size);

    /* Prepare parameters */
    oe_hostfs_rmdir_args_t* pargs_in = (oe_hostfs_rmdir_args_t*)input_buffer;
    oe_hostfs_rmdir_args_t* pargs_out = (oe_hostfs_rmdir_args_t*)output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers are valid */
    if (!input_buffer || !output_buffer)
    {
        _result = OE_INVALID_PARAMETER;
        goto done;
    }
    /* Set in and in-out pointers */
    OE_SET_IN_POINTER(pathname, pargs_in->pathname_len * sizeof(char));

    /* Set out and in-out pointers. In-out parameters are copied to output
     * buffer. */
    OE_SET_OUT_POINTER(err, (1 * sizeof(int)));

    /* Call user function */
    pargs_out->_retval =
        oe_hostfs_rmdir((const char*)pargs_in->pathname, pargs_in->err);

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out))
        pargs_out->_result = _result;
}

/*ocall function table*/
static oe_ocall_func_t __oe_ocall_function_table[] = {
    (oe_ocall_func_t)ocall_oe_hostfs_open,
    (oe_ocall_func_t)ocall_oe_hostfs_read,
    (oe_ocall_func_t)ocall_oe_hostfs_write,
    (oe_ocall_func_t)ocall_oe_hostfs_lseek,
    (oe_ocall_func_t)ocall_oe_hostfs_close,
    (oe_ocall_func_t)ocall_oe_hostfs_dup,
    (oe_ocall_func_t)ocall_oe_hostfs_opendir,
    (oe_ocall_func_t)ocall_oe_hostfs_readdir,
    (oe_ocall_func_t)ocall_oe_hostfs_rewinddir,
    (oe_ocall_func_t)ocall_oe_hostfs_closedir,
    (oe_ocall_func_t)ocall_oe_hostfs_stat,
    (oe_ocall_func_t)ocall_oe_hostfs_access,
    (oe_ocall_func_t)ocall_oe_hostfs_link,
    (oe_ocall_func_t)ocall_oe_hostfs_unlink,
    (oe_ocall_func_t)ocall_oe_hostfs_rename,
    (oe_ocall_func_t)ocall_oe_hostfs_truncate,
    (oe_ocall_func_t)ocall_oe_hostfs_mkdir,
    (oe_ocall_func_t)ocall_oe_hostfs_rmdir,
    NULL};

oe_result_t oe_create_oe_enclave(
    const char* path,
    oe_enclave_type_t type,
    uint32_t flags,
    const void* config,
    uint32_t config_size,
    oe_enclave_t** enclave)
{
    return oe_create_enclave(
        path,
        type,
        flags,
        config,
        config_size,
        __oe_ocall_function_table,
        18,
        enclave);
}

OE_EXTERNC_END
