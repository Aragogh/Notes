(TeX-add-style-hook
 "Notes.tex"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("fontenc" "T1") ("ulem" "normalem") ("algorithm" "plain")))
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "inputenc"
    "fontenc"
    "graphicx"
    "grffile"
    "longtable"
    "wrapfig"
    "rotating"
    "ulem"
    "amsmath"
    "textcomp"
    "amssymb"
    "capt-of"
    "hyperref"
    "fancyhdr"
    "extramarks"
    "amsthm"
    "amsfonts"
    "tikz"
    "algorithm"
    "algpseudocode"
    "nameref"
    "cite"
    "tikz-cd"
    "mathrsfs")
   (TeX-add-symbols
    '("bb" 1)
    '("sous" 1)
    '("sur" 1)
    "Hom")
   (LaTeX-add-amsthm-newtheorems
    "lemma"
    "exercise"))
 :latex)

