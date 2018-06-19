#ifndef MEDIA_H
#define MEDIA_H

#include <QString>
#include <QVector>
#include <QMetaType>
#include <QVariant>
#include <QMutex>
#include <QPixmap>

struct Sequence;

struct MediaStream {
	int file_index;
	int video_width;
	int video_height;
	bool infinite_length;

    // preview thumbnail/waveform
    bool preview_done;
    QImage preview;
    QMutex preview_lock;
    int preview_audio_index;
};

struct Media
{
    Media();
    ~Media();

	QString url;
	QString name;
	bool is_sequence;
	int64_t length;
    QVector<MediaStream*> video_tracks;
    QVector<MediaStream*> audio_tracks;
	Sequence* sequence;
    int save_id;
	long get_length_in_frames(float frame_rate);
};

#endif // MEDIA_H