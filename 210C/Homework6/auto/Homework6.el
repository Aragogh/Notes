(TeX-add-style-hook
 "Homework6"
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
    '("fk" 1)
    '("bb" 1)
    '("sous" 1)
    '("sur" 1)
    "Hom"
    "Tor"
    "Ext"
    "iso"
    "hmwkTitle"
    "hmwkDueDate"
    "hmwkClass"
    "hmwkClassInstructor"
    "hmwkAuthorName")
   (LaTeX-add-environments
    "lemma"
    "exercise"))
 :latex)

