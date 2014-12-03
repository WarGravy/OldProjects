;Problem 1A
(define (is-set? L)
	(cond ((null? L) #t)
	      ((contains? (car L) (cdr L)) #f)
	      (else (is-set? (cdr L)))
	)
)

(define (contains? v L)
	(cond ((null? L) #f)
	      ((equal? v (car L)) #t)
	      (else (contains? v (cdr L)))
	)
)
;Problem 1B
(define (make-set L)
	(cond ((null? L) L)
	      ((contains? (car L) (cdr L)) (make-set (cdr L)))
	      (else (cons (car L) (make-set (cdr L))))
	)
)

;Problem 1C
(define (subset? A S) 
	(cond ((null? S) #f)
	      ((equal? A S) #t)
	      (else (or (subset? A (cdr S)) (subset? A (reverse (cdr (reverse S))))))
	)
)

;Problem 1D
(define (union A B)
	(make-set (append A B))
)

;Problem 1E
(define (intersection A B)
	(make-set (dupes (append A B)))
)

(define (dupes S)
	(cond ((null? L) L)
	      ((contains? (car L) (cdr L)) (append (car L) (dupes (cdr L))))
	      (else (dupes (cdr L)))
	)
)

;Problem 2
(define T '(13 
		(5 
		   (1 () ()) 
		   (8 () (9 () ()))
		) 
		(22 
		    (17 () ()) 
		    (25 () ())
                 )
            )
)

(define (val T)
	(car T)
)
(define (left T)
	(car (cdr T))
)
(define (right T)
	(car (reverse T))
)
;Problem 2A
(define (tree-member? V T)
	(cond ((null? T) #f)
	      ((equal? V (val T)) #t)
	      (else (or (tree-member? V (left T)) (tree-member? V (right T))))
	) 
)
;Problem 2B
(define (preorder T)
	(cond ((null? T) T)
	      (else (append (list (val T)) (append (preorder (left T)) (preorder (right T)))))
	) 
)
;Problem 2C
(define (inorder T)
	(cond ((null? T) T)
	      (else (append (inorder (left T)) (append (list (val T)) (inorder (right T)))))
	) 
	
)
;Problem 3
(define (deep-delete V L)
	(cond ((null? L) L)
	      ((and (number? (car L))(= V (car L))) (deep-delete V (cdr L)))
	      ((not (number? (car L))) (cons (deep-delete V (car L)) (deep-delete V (cdr L))))
	      (else (append (list (car L)) (deep-delete V (cdr L))))
	)
)
