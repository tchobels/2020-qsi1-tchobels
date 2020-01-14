open Framework;
open TennisKata.Game;

describe("Given PlayerOne then PlayerTwo is different", ({test}) => {
  test("Given PlayerOne then PlayerTwo is different", ({expect}) => {
    expect.notEqual(PlayerOne, PlayerTwo)
  })
});

describe("Given deuce when PlayerOne wins then score is correct", ({test}) => {
  test("Given deuce when PlayerOne wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerOne), Advantage(PlayerOne))
  });
});

describe("Given deuce when PlayerTwo wins then score is correct", ({test}) => {
  test("Given deuce when PlayerTwo wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerTwo), Advantage(PlayerTwo))
  });
});

describe("Given advantage when advantaged player wins then score is correct", ({test}) => {
  test("Given advantage when advantaged player wins then score is correct",({expect}) => {
      let advantagedPlayer = PlayerOne;
      let winner = advantagedPlayer;
      expect.equal(scoreWhenAdvantage(advantagedPlayer, winner),Game(advantagedPlayer),);
    });
});

describe("Given advantage when the other player wins then score is Deuce", ({test}) => {
  test("Given advantage when the other player wins then score is Deuce",({expect}) => {
      let advantagedPlayer = PlayerOne;
      let winner = other(advantagedPlayer);
      expect.equal(scoreWhenAdvantage(advantagedPlayer, winner),Deuce,);
    });
});

describe("Given player: 40 when wins then score is Game for this player", ({test}) => {
  test("Given player: 40 when wins then score is Game for this player",({expect}) => {
    let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
    expect.equal(scoreWhenForty(fortyThirty, fortyThirty.player),Game(fortyThirty.player),);
  });
});

describe("Given player: 40 | other : 30 when other wins then score is Deuce", ({test}) => {
  test("Given player: 40 | other : 30 when other wins then score is Deuce",({expect}) => {
     let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
     expect.equal(scoreWhenForty(fortyThirty, other(fortyThirty.player)),Deuce,);
   });
});


describe("Given player: 40 | other : 0 when other wins then score is fortyFifteen", ({test}) => {
  test("Given player: 40 | other : 0 when other wins then score is fortyFifteen",({expect}) => {
      let fortyLove = {player: PlayerOne, otherPlayerPoint: Love};
      let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
      expect.equal(scoreWhenForty(fortyLove, other(fortyLove.player)),Forty(fortyFifteen),);
    });
});

describe("Given player: 15 | other : 15 when player wins then score is 30/15", ({test}) => {
  test("Given player: 15 | other : 15 when player wins then score is 30/15",({expect}) => {
    let fifteenFifteen = {playerOne: Fifteen, playerTwo: Fifteen};
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    expect.equal(scoreWhenPoints(fifteenFifteen, PlayerOne),Points(thirtyFifteen),);
  });
});

describe("Given player: 0 | other : 15 when other wins then score is 0/30", ({test}) => {
  test("Given player: 0 | other : 15 when other wins then score is 0/30",({expect}) => {
    let loveFifteen = {playerOne: Love, playerTwo: Fifteen};
    let loveThirty = {playerOne: Love, playerTwo: Thirty};
    expect.equal(scoreWhenPoints(loveFifteen, PlayerTwo),Points(loveThirty),);
  });
});

describe("Given player: 30 | other : 15 when player wins then score is 40/15", ({test}) => {
  test("Given player: 30 | other : 15 when player wins then score is 40/15",({expect}) => {
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
    expect.equal(scoreWhenPoints(thirtyFifteen, PlayerOne),Forty(fortyFifteen),);
  });
});

describe("Test string_of_player for PlayerOne/PlayerTwo : Player 1 / Player 2", ({test}) => {
  test("Test string_of_player for PlayerOne and PlayerTwo : Player 1 / Player 2",({expect}) => {
    expect.equal(string_of_player(PlayerOne),"Player 1",);
    expect.equal(string_of_player(PlayerTwo),"Player 2",);
  });
});

describe("Test string_of_point for Love/fifteen/thirty : 0/15/30", ({test}) => {
  test("Test string_of_point for Love/fifteen/thirty : 0/15/30",({expect}) => {
    expect.equal(string_of_point(Love),"0",);
    expect.equal(string_of_point(Fifteen),"15",);
    expect.equal(string_of_point(Thirty),"30",);
  });
});

describe("Test string_of_score for Points : playerOne 0|15|30-0|15|30 playerTwo", ({test}) => {
  test("Test string_of_score for Points",({expect}) => {
    let loveFifteen = {playerOne: Love, playerTwo: Fifteen};
    let loveThirty = {playerOne: Love, playerTwo: Thirty};
    let fifteenLove = {playerOne: Fifteen, playerTwo: Love};
    let fifteenFifteen = {playerOne: Fifteen, playerTwo: Fifteen};
    let fifteenThirty = {playerOne: Fifteen, playerTwo: Thirty};
    let thirtyLove = {playerOne: Thirty, playerTwo: Love};
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    let thirtyThirty = {playerOne: Thirty, playerTwo: Thirty};

    expect.equal(string_of_score(Points(loveFifteen)),"Player 1 0-15 Player 2",);
    expect.equal(string_of_score(Points(loveThirty)),"Player 1 0-30 Player 2",);
    expect.equal(string_of_score(Points(fifteenLove)),"Player 1 15-0 Player 2",);
    expect.equal(string_of_score(Points(fifteenFifteen)),"Player 1 15-15 Player 2",);
    expect.equal(string_of_score(Points(fifteenThirty)),"Player 1 15-30 Player 2",);
    expect.equal(string_of_score(Points(thirtyLove)),"Player 1 30-0 Player 2",);
    expect.equal(string_of_score(Points(thirtyFifteen)),"Player 1 30-15 Player 2",);
    expect.equal(string_of_score(Points(thirtyThirty)),"Player 1 30-30 Player 2",);
  });
});


describe("Test string_of_score for Forty : PlayerOne 40-|0|15|30 PlayerTwo : Set point / PlayerTwo 40-|0|15|30 PlayerOne : Set point", ({test}) => {
  test("Test string_of_score for Forty",({expect}) => {
    let fortyLove = {player: PlayerOne, otherPlayerPoint: Love};
    let loveForty = {player: PlayerTwo, otherPlayerPoint: Love};
    expect.equal(string_of_score(Forty(fortyLove)),"Player 1 40-0 Player 2 : Set point",);
    expect.equal(string_of_score(Forty(loveForty)),"Player 2 40-0 Player 1 : Set point",);
  });
});


describe("Test string_of_score for Deuce : PlayerOne 40-40 PlayerTwo : Deuce", ({test}) => {
  test("Test string_of_score for Deuce : PlayerOne 40-40 PlayerTwo : Deuce",({expect}) => {
   expect.equal(string_of_score(Deuce),"Player 1 40-40 Player 2 : Deuce",);
  });
});


describe("Test string_of_score for Advantage : Advantage: Player 1 / Advantage: Player 2", ({test}) => {
  test("Test string_of_score for Advantage : Advantage: Player 1 / Advantage: Player 2",({expect}) => {
    let player = PlayerOne;
    let player2 = PlayerTwo;
    expect.equal(string_of_score(Advantage(player)),"Advantage: Player 1",);
    expect.equal(string_of_score(Advantage(player2)),"Advantage: Player 2",);
  });
});


describe("Test string_of_score for Game : Player 1 wins/ Player 2  wins", ({test}) => {
  test("Test string_of_score for Game : Player 1 wins/ Player 2 wins",({expect}) => {
    let player = PlayerOne;
    let player2 = PlayerTwo;
    expect.equal(string_of_score(Game(player)),"Player 1 wins",);
    expect.equal(string_of_score(Game(player2)),"Player 2 wins",);
  });
});

