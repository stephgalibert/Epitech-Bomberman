Fbox = 1
Fibox = 2
Fplayer = 3

  -- table(success, size, dir(x,y), target(x,y))findPath(int player ,int flag);
  -- table(x,y) getPos(int numplayer);
  -- int getMood(int numplayer);
  -- void setMood(int numplayer, int moood);

ai = function(id)
    e = findPath(id,2)
    j = getMood(id)
    setMood(id, j + 1)
    k = getMood(id)
    return 0
end
