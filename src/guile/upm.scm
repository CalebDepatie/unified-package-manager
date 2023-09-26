; Defines the records required for configuring UPM
; TODO: determine a nicer file structure for this
(use-modules (rnrs records syntactic))

(define-record-type arg-map
  (fields
    (immutable upm-arg) ; string
    (immutable cmd-arg) ; string
	)
)

; TODO: Type checking
; (define (check-string arg-map
; 	(if (not (scm_string_p name))
;   (error "name must be a string")
;     name))

(define-record-type command
	(fields
		(immutable name) ; string
		(immutable args) ; list of arg-map
	)
)

(define-record-type manager
	(fields
		(immutable name)    ; string
		(immutable install) ; list of command | command
		(immutable remove)  ; list of command | command
		(immutable update)  ; list of command | command
		(immutable search)  ; list of command | command
	)
)

; (use-modules (ice-9 records))

; (define-record-type* <arg-map>
; 	arg-map make-arg-map
; 	arg-map?
; 	(upm-arg arg-map-upm-arg) ; string
; 	(cmd-arg arg-map-cmd-arg) ; string
; )

; (define-record-type* <command>
; 	command make-command
; 	command?
; 	(name command-name) ; string
; 	(args command-args) ; list of arg-map
; )

; (define-record-type* <manager>
; 	manager make-manager
; 	manager?
; 	(name manager-name) ; string
; 	(install install-commands) ; list of command | command
; 	(remove remove-commands) ; list of command | command
; 	(update update-commands) ; list of command | command
; 	(search search-commands) ; list of command | command
; )