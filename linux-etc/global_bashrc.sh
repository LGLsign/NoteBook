#
#改文件放到目录/etc下
#修改/etc/bashrc
#在最后面添加以下内容
#if [ -f /etc/global_bashrc.sh ] ; then
#        source /etc/global_bashrc.sh
#fi
#保存退出后执行命令 source bashrc
#全局配置
alias vi='vim'

_my_cd() { cd $1;ls -al; };
alias cd='_my_cd'

PS1='\n${debian_chroot:+($debian_chroot)}\[\033[1;36m\]\u\[\033[1;35m\]@\[\033[1;31m\]\H\[\033[1;34m\]:\[\033[1;33m\]$PWD\[\033[1;32m\] # \[\033[0m'

ulimit -c unlimited
