#define DR_WAV_IMPLEMENTATION
#include "dr_wav.h"

size_t sp_drwav_size(void)
{
    return sizeof(drwav);
}

int sp_drwav_init_file(drwav* pWav, const char* filename)
{
    return drwav_init_file(pWav, filename);
}

size_t sp_drwav_read_f32(drwav* pWav,
                         size_t samplesToRead,
                         float* pBufferOut)
{
    return drwav_read_f32(pWav, samplesToRead, pBufferOut);
}

size_t sp_drwav_sampcount(drwav *wav)
{
    return wav->totalSampleCount;
}

void sp_drwav_uninit(drwav *wav)
{
    drwav_uninit(wav);
}

int sp_drwav_seek_to_sample(drwav* pWav, size_t sample)
{
    return drwav_seek_to_sample(pWav, sample);
}

drwav * sp_drwav_open_mono_write(const char *filename, int sr)
{
    drwav_data_format format;
    format.container = drwav_container_riff;
    format.format = DR_WAVE_FORMAT_IEEE_FLOAT;
    format.channels = 1;
    format.sampleRate = sr;
    format.bitsPerSample = 32;

    return drwav_open_file_write(filename, &format);
}

size_t sp_drwav_write(drwav* pWav, size_t samplesToWrite, const void* pData)
{
    return drwav_write(pWav, samplesToWrite, pData);
}

void sp_drwav_close(drwav* pWav)
{
    drwav_close(pWav);
}
