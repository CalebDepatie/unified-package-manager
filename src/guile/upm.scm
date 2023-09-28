; File and definitions not currently required
; Moving back to a records based approach is my goal

; Defines the records required for configuring UPM
; TODO: determine a nicer file structure for this
; (use-modules (rnrs records syntactic))

; (add-pkg-manager
; 	"apt"
; 	"install"
; 	"remove"
; 	`("update" "upgrade")
; 	"search")

; ; -- Types --

; (define-record-type arg-map
;   (fields
;     (immutable upm-arg) ; string
;     (immutable cmd-arg) ; string
; 	)
; )

; ; TODO: Type checking
; ; (define (check-string arg-map
; ; 	(if (not (scm_string_p name))
; ;   (error "name must be a string")
; ;     name))

; (define-record-type command
; 	(fields
; 		(immutable name) ; string
; 		(immutable args) ; list of arg-map
; 	)
; )

; (define-record-type manager
; 	(fields
; 		(immutable name)    ; string
; 		(immutable install) ; list of command | command
; 		(immutable remove)  ; list of command | command
; 		(immutable update)  ; list of command | command
; 		(immutable search)  ; list of command | command
; 	)
; )

; ; -- Global Data --
; (define managers `())

; ; -- Functions --
; (define (add-manager name install remove update search)
;   (let ((new-manager (make-manager name install remove update search)))
;     (set! managers (cons new-manager managers))))

; (define (set-order order)
; 	())

; (define (run-command name args)
; 	(if (null? args)
; 		(system (command-name command))
; 		(system (command-name command) (string-join args " "))))

; (define (search name manager-name)
; 	())

; (define (install name manager-name)
; 	())

; (define (remove name manager-name)
; 	())

; (define (update name manager-name)
; 	())

