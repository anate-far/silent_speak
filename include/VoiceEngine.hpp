#ifndef VOICEENGINE_HPP
# define VOICEENGINE_HPP

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <espeak-ng/speak_lib.h>

class voiceEngine
{
	private :
		std::string 			_voiceName;
		int 					_bufferLen;
		int						_options;
	public :
		voiceEngine();
		~voiceEngine();
		void	speak(const std::string &text);
		void	test(const char *text);
};

#endif
