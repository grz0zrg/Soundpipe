#ifndef SP_DRWAV_H
#define SP_DRWAV_H
#ifndef dr_wav_h
typedef struct drwav drwav;
#endif
size_t sp_drwav_size(void);
int sp_drwav_init_file(drwav* pWav, const char* filename);
size_t sp_drwav_read_f32(drwav* pWav,
                         size_t samplesToRead,
                         float* pBufferOut);
size_t sp_drwav_sampcount(drwav *wav);
void sp_drwav_uninit(drwav *wav);
int sp_drwav_seek_to_sample(drwav* pWav, size_t sample);
drwav * sp_drwav_open_mono_write(const char *filename, int sr);
size_t sp_drwav_write(drwav* pWav, size_t samplesToWrite, const void* pData);
void sp_drwav_close(drwav* pWav);
#endif
