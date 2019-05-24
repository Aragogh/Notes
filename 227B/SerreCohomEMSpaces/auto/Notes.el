(TeX-add-style-hook
 "Notes"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("algorithm" "plain")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "fancyhdr"
    "extramarks"
    "amsmath"
    "amsthm"
    "amssymb"
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
    "theorem"
    "exercise"
    "Corollary"))
 :latex)

