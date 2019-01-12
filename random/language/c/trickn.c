\documentclass{article}
\usepackage{listings}
\usepackage{xparse}

\ExplSyntaxOn
\NewDocumentCommand{\code}{m +v}{
  \exp_args:Nx \scantokens
  {
    \string\begin{lstlisting}[\unexpanded{language=#1,numbers=none,xleftmargin=0.35cm,framesep=0mm}] #2
    \string\end{lstlisting}
  }
}
\ExplSyntaxOff

\begin{document}

\code{C}{
int x = 200;
unsigned int y = 0;
}

\end{document}
