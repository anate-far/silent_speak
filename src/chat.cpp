#include "ft.hpp"
#include "VoiceEngine.hpp"
#include "Buffer.hpp"
#include <string>
#include <termios.h>
#include <unistd.h>

void	setRawMode(int enable)
{
	static struct termios	oldT;
	static struct termios	newT;

	if (enable)
	{
		tcgetattr(STDIN_FILENO, &oldT);
		newT = oldT;
		newT.c_lflag &= ~(ICANON);
		tcsetattr(STDIN_FILENO, TCSANOW, &newT);
	}
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &oldT);
}

void	run_chat()
{
	buffer speak_buff(10);
	voiceEngine speaker; 
	char	char_buff[256];
	char	c = 0;
	int		i = 0;

	setRawMode(1);
	while (c != '\n')
	{
		if (read(STDIN_FILENO, &c, 1)  > 0)
		{
			char_buff[i] = c;
			if (i > 255 || c == ' ' || c == '\n')
			{
				std::string s(char_buff);
				speak_buff.push(s);
				bzero(char_buff, 256);
				i = 0;
			}
			else
				i++;
			if (!speak_buff.isEmpty())
			{
				std::string s1 = speak_buff.pop();
				speaker.test(s1.c_str());
			}
		}
	}
	setRawMode(0);
}
