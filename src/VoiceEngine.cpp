#include "VoiceEngine.hpp"

espeak_AUDIO_OUTPUT output = AUDIO_OUTPUT_SYNCH_PLAYBACK;
char *path = NULL;
void* user_data;
unsigned int *identifier;

voiceEngine::voiceEngine() : _voiceName("fr"), _bufferLen(500), _options(0)
{
	espeak_Initialize(output, _bufferLen, path, _options);
	espeak_SetVoiceByName(_voiceName.c_str());
}
voiceEngine::~voiceEngine(){}

void	voiceEngine::speak(const std::string &text)
{
	std::cout << _voiceName << " : " << text << std::endl;
}

void	voiceEngine::test(const char *text)
{
 	unsigned int			pos = 0;
	espeak_POSITION_TYPE	pos_type = POS_CHARACTER;
	unsigned int			end_pos = 0;
	unsigned int			flags = espeakCHARS_AUTO;

   	espeak_Synth(text, _bufferLen, pos, pos_type, end_pos, flags, identifier, user_data);
	espeak_Synchronize();
}
