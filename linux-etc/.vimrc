"""""""""""""""""""""""""""""""""""""""""
" vimrc 1.0 自用版
" 作者：sign
" 环境：
" 需要 vim8.1 或以上版本
" 使用 tagbar 需要安装 ctags5.8 或以上版本
" 使用 Ack 请安装 ripgrep
""""""""""""""""""""""""""""""""""""""""" 

" 加载插件管理模块
call pathogen#infect()
syntax on
filetype plugin indent on

" 全局配置

" 不使用vi的键盘模式, 使用vim
set nocompatible

" 用浅色高亮当前行
autocmd InsertLeave * se nocul
autocmd InsertEnter * se cul

" 智能对齐
set smartindent 
"set autoindent
"set cindent

" 折叠
" manual   "手工定义折叠
" indent   "用缩进表示折叠
" expr　   "用表达式来定义折叠
" syntax   "用语法高亮来定义折叠
" diff     "对没有更改的文本进行折叠
" marker   "用标志折叠
"set foldmethod = syntax
"set foldclumn=0         "设置折叠标识列
"set flodlevel=3         "折叠等价, 这里表示大于shiftwith 3 倍的折叠将关闭

" 关闭输入错误的提示音
" set noeb


" 处理未保存或只读文件时弹出提示框
set confirm

" 设置tab的宽度
set tabstop=4
set softtabstop=4
set shiftwidth=4              "统一缩进为4
"set noexpandtab/expandtab    "设置tab替换空格
"%retab!                      "设置是否把文件中的空格换成tab或者tab换成空格(取决于上面expand设置), 加!表示处理所有tab/空格, 不加则指出来行首tab/空格

" 设置退格键删除模式
set backspace=2

" 显示行号
set number

" 编码设置
set encoding=utf-8
set fileencodings=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936,utf-16,big5,euc-jp,latin1

" 设置主题
"color asmanian2

" 配色方案
colorscheme molokai  

set t_Co=256
set background=dark
let g:rehash256 = 1
let g:molokai_original = 1

" 显示状态行当前设置
"set statusline

" 设置状态行显示常用信息
" %F 完整文件路径名
" %m 当前缓冲被修改标记
" %m 当前缓冲只读标记
" %h 帮助缓冲标记
" %w 预览缓冲标记
" %Y 文件类型
" %b ASCII值
" %B 十六进制值
" %l 行数
" %v 列数
" %p 当前行数占总行数的的百分比
" %L 总行数
" %{...} 评估表达式的值，并用值代替
" %{"[fenc=".(&fenc==""?&enc:&fenc).((exists("+bomb") && &bomb)?"+":"")."]"} 显示文件编码
" %{&ff} 显示文件类型
set ruler
set statusline=%F%m%r%h%w%=\ \ %Y\ \ \|\ \ %{\"\".(&fenc==\"\"?&enc:&fenc).((exists(\"+bomb\")\ &&\ &bomb)?\"+\":\"\").\"\"}\ \ \|\ \ %{&ff}\ \ \|\ \ asc=%03.3b\ \ \|\ \ line\ %l\ column\ %v\ \ \|\ \ total\ %L\ \ 

" 设置 laststatus = 0 ，不显式状态行
" 设置 laststatus = 1 ，仅当窗口多于一个时，显示状态行
" 设置 laststatus = 2 ，总是显式状态行
set laststatus=2

" 搜索设置
set hlsearch
set incsearch        "逐渐高亮
"set ignorecase      "忽略大小写

" 语言设置
"set guifont=Menlo:h16:cANSI      "设置字体
"set langmenu=zn_CN.UTF-8
"set helplang=cn                  "语言设置

" 自动保存，加载
set autoread
set autowriteall

" 突出显示当前行
set cursorline

" 禁止生成临时文件
set nobackup

set noswapfile
" 带有如下符号的单词不要被换行分割
set iskeyword+=_,$,@,%,#,-

" 字符间插入的像素行数目
set linespace=0

" 保存全局变量
set viminfo+=!

" 增强模式中的命令行自动完成操作
"set wildmenu

" 允许backspace和光标键跨越行边界
set whichwrap+=<,>,h,l

" 可以在buffer的任何地方使用鼠标（类似office中在工作区双击鼠标定位）
"set mouse=a
"set selection=exclusive
"set selectmode=mouse,key
"
" 通过使用: commands命令，告诉我们文件的哪一行被改变过
set report=0

" 在被分割的窗口间显示空白，便于阅读
set fillchars=vert:\ ,stl:\ ,stlnc:\

" 高亮显示匹配的括号
set showmatch

" 匹配括号高亮的时间（单位是十分之一秒）
set matchtime=1

" 光标移动到buffer的顶部和底部时保持3行距离
"set scrolloff=3

" vim-go 插件
let g:go_disable_autoinstall= 0
let g:go_highlight_functions = 1
let g:go_highlight_methods = 1
let g:go_highlight_structs = 1
let g:go_highlight_operators = 1
let g:go_highlight_build_constraints = 1

" neocomplete 代码补全插件
let g:neocomplete#enable_at_startup = 1

" NERDTree 文件目录插件
" 窗口设置
let g:NERDChristmasTree=0
let g:NERDTreeWinSize=30
let g:NERDTreeChDirMode=2
let g:NERDTreeWinPos="left"

" 显示书签列表
let g:NERDTreeShowBookmarks=1

" 修改默认箭头符号
let g:NERDTreeDirArrowExpandable = '+'
let g:NERDTreeDirArrowCollapsible = '-'

" 设置忽略文件
let g:NERDTreeIgnore=['\~$', '\.pyc$', '\.swp$']

" Automatically open a NERDTree if no files where specified
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif

" Close vim if the only window left open is a NERDTree
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif

" Open a NERDTree
nmap <F2> :NERDTreeToggle<cr>

" syntastic 语法检查插件
" 设置error和warning的标志
"let g:syntastic_enable_signs = 1
"let g:syntastic_error_symbol='✗'
"let g:syntastic_warning_symbol='►'

" 总是打开Location List(相当于QuickFix)窗口, 如果syntastic因为与其他插件冲突而经常崩溃, 将下面选项置0
let g:syntastic_always_populate_loc_list = 1

" 设置Locaton List, 默认值为2
" 0 表示关闭自动打开和自动关闭
" 1 表示自动打开自动关闭
" 2 表示发现错误时不自动打开, 当修正以后没有再发现错误时自动关闭
" 3 表示自动打开，但不自动关闭
let g:syntastic_auto_loc_list = 1

" 修改Locaton List窗口高度
let g:syntastic_loc_list_height = 5

" 打开文件时自动进行检查
let g:syntastic_check_on_open = 1

" 自动跳转到发现的第一个错误或警告处
let g:syntastic_auto_jump = 1

"进行实时检查，如果觉得卡顿，将下面的选项置为1
let g:syntastic_check_on_wq = 0

"高亮错误
let g:syntastic_enable_highlighting = 1

"让syntastic支持C++11
let g:syntastic_cpp_checkers = ['gcc']
let g:syntastic_cpp_compiler = 'gcc'
let g:syntastic_cpp_compiler_options = '-std=c++11 -lstdc++'

" 设置pyflakes为默认的python语法检查工具
let g:syntastic_python_checkers = ['pyflakes']

" statusline设置
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

" 修复syntastic使用:lnext和:lprev出现的跳转问题，同时修改键盘映射使用sn和sp进行跳转
function! <SID>LocationPrevious()                       
  try                                                   
    lprev                                               
  catch /^Vim\%((\a\+)\)\=:E553/                        
    llast                                               
  endtry                                                
endfunction                                             
function! <SID>LocationNext()                           
  try                                                   
    lnext                                               
  catch /^Vim\%((\a\+)\)\=:E553/                        
    lfirst                                              
  endtry                                                
endfunction                                             
nnoremap <silent> <Plug>LocationPrevious    :<C-u>exe 'call <SID>LocationPrevious()'<CR>                                        
nnoremap <silent> <Plug>LocationNext        :<C-u>exe 'call <SID>LocationNext()'<CR>
nmap <silent> sp    <Plug>LocationPrevious              
nmap <silent> sn    <Plug>LocationNext
"关闭syntastic语法检查, 鼠标复制代码时用到, 防止把错误标志给复制了
nnoremap <silent> <Leader>ec :SyntasticToggleMode<CR>
function! ToggleErrors()
    let old_last_winnr = winnr('$')
    lclose
    if old_last_winnr == winnr('$')
        " Nothing was closed, open syntastic error location panel
        Errors
    endif
endfunction

" CTags的设定  
let Tlist_Sort_Type = "name"        " 按照名称排序  
let Tlist_Use_Right_Window = 0      " 在左侧显示窗口  
let Tlist_Compart_Format = 1        " 压缩方式  
let Tlist_Exist_OnlyWindow = 1      " 如果只有一个buffer，kill窗口也kill掉buffer  
let Tlist_File_Fold_Auto_Close = 0  " 不要关闭其他文件的tags  
let Tlist_Enable_Fold_Column = 0    " 不要显示折叠树  
"autocmd FileType java set tags+=D:\tools\java\tags  
"autocmd FileType h,cpp,cc,c set tags+=D:\tools\cpp\tags  
let Tlist_Show_One_File = 1            "不同时显示多个文件的tag，只显示当前文件的
"设置tags  
set tags=tags  
set autochdir    "

" Ctags 生成命令
" ctags -R --c++-kinds=+px --fields=+iaS --extra=+q
" 选项c++-kinds 用于指定C++语言的 tags记录类型,  --c-kinds用于指定c语言的，  通用格式是  --{language}-kinds
" 选项 fileds 用于指定每条标记的扩展字段域                                                                          
" extra 选项用于增加额外的条目:   f表示为每个文件增加一个条目，  q为每个类增加一个条目

" Tagbar 类视图插件
" 快捷键映射
nnoremap <F3> <ESC>:TagbarOpenAutoClose<CR>

" 窗口大小
let g:tagbar_width = 30

" 排序方式，为0则按名字排序
"let g:tagbar_sort = 0

" 折叠层级
let g:tagbar_foldlevel = 2

" 颜色设置
" class, struct
highlight TagbarScope guifg=Green ctermfg=Green
" function
highlight TagbarSignature guifg=Blue ctermfg=Blue

" ACK 搜索全局引用插件
" 快捷键映射
nmap <S-F>F :Ack!<SPACE><CR>
nmap <S-F>f :Ack!<SPACE>

" 调用rg进行搜索
if executable('rg')
  let g:ackprg = 'rg --vimgrep'   "需要加参数加这里
endif

"高亮搜索关键词
let g:ackhighlight = 1

"修改快速预览窗口高度为15
let g:ack_qhandler = "botright copen 15"

"在QuickFix窗口使用快捷键以后，自动关闭QuickFix窗口
let g:ack_autoclose = 1

"使用ack的空白搜索，即不添加任何参数时对光标下的单词进行搜索，默认值为1，表示开启，置0以后使用空白搜索将返回错误信息
let g:ack_use_cword_for_empty_search = 1

"部分功能受限，但对于大项目搜索速度较慢时可以尝试开启
"let g:ack_use_dispatch = 1

" 其他设置

" 如果打开的是下列文件, 则设置tab为4个空格
autocmd BufNewFile,BufRead  *.cpp,.[ch],*.sh,*.java,*.py,*.lua,*.go set expandtab

" 新建.c,.h,.sh,.java文件，自动插入文件头 
" autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()" 
""定义函数SetTitle，自动插入文件头 
func SetTitle() 
    "如果文件类型为.sh文件 
    if &filetype == 'sh' 
        call setline(1,"\#########################################################################") 
        call append(line("."), "\# File Name: ".expand("%")) 
        call append(line(".")+1, "\# Author: ma6174") 
        call append(line(".")+2, "\# mail: ma6174@163.com") 
        call append(line(".")+3, "\# Created Time: ".strftime("%c")) 
        call append(line(".")+4, "\#########################################################################") 
        call append(line(".")+5, "\#!/bin/bash") 
        call append(line(".")+6, "") 
    else 
        call setline(1, "/*************************************************************************") 
        call append(line("."), "    > File Name: ".expand("%")) 
        call append(line(".")+1, "    > Author: ma6174") 
        call append(line(".")+2, "    > Mail: ma6174@163.com ") 
        call append(line(".")+3, "    > Created Time: ".strftime("%c")) 
        call append(line(".")+4, " ************************************************************************/") 
        call append(line(".")+5, "")
    endif
    if &filetype == 'cpp'
        call append(line(".")+6, "#include<iostream>")
        call append(line(".")+7, "using namespace std;")
        call append(line(".")+8, "")
    endif
    if &filetype == 'c'
        call append(line(".")+6, "#include<stdio.h>")
        call append(line(".")+7, "")
    endif
    "新建文件后，自动定位到文件末尾
    autocmd BufNewFile * normal G
endfunc
