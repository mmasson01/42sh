42sh
====
42sh					Manual for the 42sh					42sh(1)



NAME
	42sh -- Unix environement based on zsh

LIBRARY
	Standart C Library (libc, -lc)

SYNOPSIS
	./42sh -- No argumenst are required.

DESCRIPTION
	42sh is an environement Unix, all command are parsing into
	our parser to creat node and execute correctly with prioritly
	the command. All the cmd line are execute with execve.
	This builtins is include:

	-cd [args](with cd~ cd(without argument to go home directly)
	and cd- to get the value of ENV/OLDPWD=...)
	-echo [args]
	-exit [args](you can exit with a value, by default the exit
	value is 0. This value is returned by 42sh)
	-env [args](-i option execute the cmd without env-variable.
	Env alone print all the variable of environement and you
	can also change a value of this by an args of env)
	-setenv [var] [value_to_set] (To change or add a variable)
	-unsetenv [var] (To unset a variable, use with precaution)

	You can use all the oprerands like :
	-">", ">>", "<" and "|"
	The logical :
	-"&&" and "||"
	And the separator :
	-";"

	Our shell include somme feature with the termcaps library,
	like eition of line and some others, exemple:

	-Home & end place your cursor to the first or last character
	-Control + shift + (left || right) gonna move you faster then
	using arrow. You can deplace by word per word with this
	amazing termcaps :
	-Shift initialize the selection mode
	-Shift + right arrow paste your selection
	-Shift + up arrow cut your selection
	-Esc stop the selection mode

	Sound of end of line or start line is set by default. You
	can turn it off by pressing F10.
	And you can set the value of time if you need to collaborate
	with some people in the world, then you can know how time is
	it into his/her country (time in prompt). The position by
	default is set at Paris but you can check world time by
	setting the VAR/POSITION, exemple: setenv POSITION LONDON.
	ALL this country is available :
	-LONDON
	-SAN_FRANCISCO
	-NEW-YORK
	-SHANGHAI
	-TOKYO
	-PARIS

RETURN VALUES
	By default, if you tape exit, 42sh exit with the correct value
	equal to zero. But you can exit with a value between 0 and 255.

ERRORS
	No errors occurs since he is finished. And he get an awesome crash
	test..

SEE ALSO
	zsh(1), sh(1), bash(1), and some others, but the best is 42sh.

CONTACT
	Our contact in the developement group is xiaowanyou42@gmail.com
	Developement teams:
	-Xiaowan You
	-Cristophe Ochin
	-Moustafa Faid
	-Julien Mery
	-Maxence Masson


42sh v1.0				MARCH 22, 2k14							42sh(1)
