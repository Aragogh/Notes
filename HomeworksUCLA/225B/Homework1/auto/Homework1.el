(TeX-add-style-hook
 "Homework1"
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
    "tikz-cd")
   (TeX-add-symbols
    '("sous" 1)
    '("sur" 1)
    "hmwkTitle"
    "hmwkDueDate"
    "hmwkClass"
    "hmwkClassInstructor"
    "hmwkAuthorName")
   (LaTeX-add-amsthm-newtheorems
    "lemma"
    "exercise"))
 :latex)

