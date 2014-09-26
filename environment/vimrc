set nocompatible

imap jj <Esc>

filetype plugin indent on
syntax on

set sw=2 sts=2 et ws ic sc is hls wrap hid 

set wmnu so=3 fo+=j
colorscheme delek

nmap Y y$

map -<space> :noh<cr>

au BufEnter *.java map -c :up<cr>:make %:r.class<cr>:!java %:r < %:r.in\|cat -e<cr>
au BufEnter *.cpp map -c :up<cr>:make %:r<cr>:!./%:r < %:r.in\|cat -e<cr>
