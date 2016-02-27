#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

export LANG=fr_FR.UTF-8
#export WINEARCH=win32
 #Pimp
PS1='\[\e[1;32m\][\u@\h]\[\e[m\] \[\e[1;36m\]\w\[\e[m\] \[\e[1;32m\]\$\[\e[m\] \[\e[m\]'
alias mqn='man'
alias ls='ls -G --color=auto'
alias ll='ls -lGa --color=auto'
alias gccw='gcc -Wall -Werror -Wextra'
alias pdf='epdfview'
alias grep='grep --color=auto'
alias jabber='gajim'
alias ga='git add'
alias gp='git push'
alias gc='git commit -m'
