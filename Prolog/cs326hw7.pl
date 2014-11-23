/*Zachary Carlson
	CS 326
	HW 7
*/

/*Problem 1: rev = reverse because reverse is a keyword for my swi-prolog?*/
/*I got a lot of help with combine from: www.learnprolognow.org*/
rev([],[]).
rev([H|T], R) :- rev(T, RTail), combine(RTail, [H], R).

combine([],L,L). 
combine([H|T],L2,[H|L3]) :- combine(T,L2,L3).

/*Problem 2*/
take([H|_], 0, []).
take([H|_], 1, [H]).
take([F,H|T], N, [F,H|LT]) :- J is N - 1, take([H|T], J, [H|LT]).

/*Problem 3 Definitions*/
tree(nil).
tree(node(_,Left,Right)) :- tree(Left), tree(Right).

/*Problem 3A*/
nleaves(nil, 0).
nleaves(node(_,Left,nil), 1).
nleaves(node(_,nil,Right), 1).
nleaves(node(_,Left,Right), N) :- nleaves(Left, X), nleaves(Right,Y), N is X + Y.

/*Problem 3B*/
treeMember(X, node(X,Left,Right)).
treeMember(X, node(_,Left,Right)) :- treeMember(X, Left).
treeMember(X, node(_,Left,Right)) :- treeMember(X, Right).

/*Problem 3C*/
preOrder(nil,[]).
preOrder(node(X,nil,nil),[X]).
preOrder(node(X,Left,Right), L) :- preOrder(Left, L1), preOrder(Right, L2), combine([X|L1], L2, L).

/*Problem 3D*/
height(nil, 0).
height(node(_,nil,nil), 1).
height(node(_, Left, nil), N) :- height(Left, J), N is J + 1.
height(node(_, nil, Right), N) :- height(Right, J), N is J + 1.
height(node(_, Left, Right), N) :- height(Left, K), height(Right, J),K >= J, N is K + 1.
height(node(_, Left, Right), N) :- height(Left, K), height(Right, J),K < J, N is J + 1.

/*Problem 4*/
insert(N, [], [N]).
insert(N, [H|T], L) :- L = [N, H | T], N =< H.
insert(N, [H|T], L) :- N > H, insert(N, T, L1), L = [H|L1].

/*Extra Credit Flatten*/
flatten([],[]).
flatten([X],[X]).
flatten([X,[H]|T], L) :- flatten(H, L1), flatten(T, L2), combine([X|L1], L2, L).
