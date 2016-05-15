;----------------------
; configuration globale
;----------------------

; accents
;(standard-display-european 1)
;(setq icon-map-list '(x-gtk-stock-map))
(tool-bar-mode 0)

; touches suppr, home et end
(global-set-key [delete] 'delete-char)
(global-set-key [home] 'beginning-of-line)
(global-set-key [end] 'end-of-line)

; Afficher le numero de ligne
(line-number-mode 1)
(column-number-mode 1)

;; Le silence est d'or
(defun etk-dummy-ring-bell-function ()
  nil)
(setq ring-bell-function `etk-dummy-ring-bell-function)

;Pour activer iswitchb
(iswitchb-mode t)

;Pour ne pas utiliser de tab mais des espaces Ã  la place
; Utile de le mettre que pour ml
(setq-default indent-tabs-mode nil)

; Mettre quatre espaces pour l'indentation
(setq c-basic-offset 4)

; M-g pour aller Ã  la x-iÃ¨me ligne
(global-set-key [(meta g)] 'goto-line)

;; ========== Support Wheel Mouse Scrolling ==========
;; http://homepages.inf.ed.ac.uk/s0243221/emacs/
(mouse-wheel-mode t)

;Pour sauver l'historique
(savehist-mode 1)


;----------
; mode CAML
;----------

(add-to-list 'load-path "~/.emacs.d/tuareg")
(if (and (boundp 'window-system) window-system)
    (require 'font-lock))
 
(setq-default auto-mode-alist
              (cons '("\\.ml[iylp]?" . tuareg-mode)
                    auto-mode-alist))
(setq-default tuareg-in-indent 0)
(autoload 'tuareg-mode "tuareg" "Major mode for editing Caml code." t)
(autoload 'run-caml "inf-caml" "Run an inferior Caml process." t)
(autoload 'camldebug "camldebug" "Run the Caml debugger." t)
(defvar caml-mode-hook
  '(lambda () (modify-syntax-entry ?_ "w" caml-mode-syntax-table)))
 
(add-hook 'tuareg-mode-hook
          '(lambda ()
             (define-key tuareg-mode-map "\M-q" 'fill-paragraph)
))
 
(add-hook 'tuareg-load-hook
          '(lambda ()
             (define-key tuareg-mode-map [f2] 'tuareg-eval-phrase)
             (define-key tuareg-mode-map [f5] 'compile)
             (define-key tuareg-mode-map [f6] 'recompile)
             (define-key tuareg-mode-map [f7] 'next-error)
             ; (load-library "camlit")
             ; (camlit-minor-mode)
             ))

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(delete-selection-mode nil)
 '(global-font-lock-mode t nil (font-lock))
 '(inhibit-startup-screen t)
 '(show-paren-mode t nil (paren))
 '(text-mode-hook (quote (turn-on-auto-fill text-mode-hook-identify)))
 '(transient-mark-mode t))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
