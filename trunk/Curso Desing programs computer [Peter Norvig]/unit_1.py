## WRITE A POKER PROGRAM ##
## ?? --> problem(understand) --> spec(specify)--->code(design)


def poker(hands):
  "return the best hand: poker ([hand,...]) => hand"
  return max(hands,key = hand_rank)

def hand_rank(hand):
 "Return a value indicating the ranking of a hand. "
  ranks = card_ranks(hand)
  if straight(ranks) and flush(hand):
	return (8, max(ranks)) # 2 3 4 5 6 (8, 6) 6 7 8 9 T (8, 10)
  elif kind(4,ranks):
	return (7, kind(4, ranks),kind(1, ranks) #  9 9 9 9 3 (7,9,3)
  elif kind(3, ranks) and kind(2,ranks):
	return (6, kind(3, ranks), kind(2, ranks)
  elif flush(hand):
	return (5, ranks)
  elif straight(ranks):
	return (4, max(ranks))
  elif kind(3,ranks):
	return (3, kind(3, ranks), ranks)
  elif two_pair(ranks)
	return (2,two_pair(ranks), ranks)
  elif kind (2, ranks):
	return (1, kind(2, ranks), ranks)
  else:
	return (0, ranks)

def card_ranks(cards):
  "Return a list of the ranks, sorted with higher first."
  ranks = ['--23456789TJQKA'.index(r) for r,s in hands]
  ranks.sort(reverse = True)
  return ranks

def straight(ranks):
  "Return True if the ordered ranks form a 5-card straight."
  return (max(ranks)-min(ranks) == 4) and len(set(ranks)) == 5

def flush(hand):
  "Return True if all the cards have the same suit."
  suits = [ s for r,s in hand]
  return len(set(suits)) == 1

def kind(n , ranks):
  """Return the first rank that this hand has exactly n of.
	Return None if there is no n-of-a-kind in the hand."""
  for r in ranks:
	if ranks.count(r) == n: return r
  return None

def test():
  "Test cases for the functions in poker program." #3 manos de cartas 
  sf = "6C 7C 8C 9C TC".split() #letra -> picas,corazones,diamantes....
  fk = "9D 9H 9S 9C 7D".split()
  fh = "TD TC TH 7C 7D".split()
  fkranks = card_ranks(fk)
  tpranks = card_ranks(tp)
  assert kind(4,fkranks) == None
  assert kind(3,fkranks) == None
  assert kind(2,fkranks) == None
  assert kind(1,fkranks) == 7
  assert two_pair(fkranks) == None
  assert two_pair(fpranks) == (9, 5)
  assert straight([9,8,7,6,5]) == True
  assert straight([9,8,8,6,5]) == False
  assert flush(sf) == True
  assert flush(fk) == False
  assert card_ranks(sf) == [10,9,8,7,6]
  assert card_ranks(fk) == [9,9,9,9,7]
  assert card_ranks(fh) ==[10,10,10,7,7]
  assert poker([sf,fk,fh]) == sf
  assert poker([fk,fh]) == fk
  assert poker([fh,fh]) == fh
  assert poker([sf]) == sf
  assert poker([sf] + 99*[fh]) == sf
  assert hand_rank(sf) == (8 ,10)
  assert hand_rank(fk) == (7, 9, 7)
  assert hand_rank(fh) == (6, 10, 7)
  
  return 'test pass'


