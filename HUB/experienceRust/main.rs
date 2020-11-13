use std::io ;
use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() == 1 {
        game_logic();
    } else if args.len() == 2 {
        if args[1] == "-h" || args[1] == "--help" {
            println!("USAGE: ./myMorpionInRust\nDESCRIPTION: Each player enter a case number to place his pawn");
        } else {
            println!("ERROR: bad argument given.");
        }
    }
}


fn game_logic() {
    let mut actual_player: u8 ;
    let mut game_tab = ["1", "2", "3",
                        "4", "5", "6",
                        "7", "8", "9"];

    println!("Player 1 : X");
    println!("Player 2 : O\n");
    print_tab(&mut game_tab);
    while !is_win(&mut game_tab).0 {
        actual_player = 1;
        play(&mut game_tab, actual_player);
        if !is_win(&mut game_tab).0 {
            actual_player = 2;
            play(&mut game_tab, actual_player);
        }
    }
    if is_win(&mut game_tab).1 == 0 {
        println!("\nThe game is finished, EQUALITY !");
    } else if is_win(&mut game_tab).1 == 1 {
        println!("\nThe game is finished, CONGRATULATIONS Player 1 (X) for your win !");
    } else {
        println!("\nThe game is finished, CONGRATULATIONS Player 2 (O) for your win !");
    }
}

fn play(game_tab: &mut [&str; 9], actual_player: u8) {

    let mut num_case = String::new() ;
    let mut index: usize ;

    loop {
        num_case.clear();
        println!("Player {}, please type the case where you want to place '{}': ", actual_player, if actual_player == 1 {'X'} else {'0'});
        io::stdin().read_line(&mut num_case).expect("Failed to read line");
        index = match num_case.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        index -= 1;
        if index >= game_tab.len() {
            println!("Case out of board !");
            continue;
        } else if game_tab[index].eq("X") || game_tab[index].eq("O") {
            println!("This case is already used !");
            continue;
        } else {
            game_tab[index] = if actual_player == 1 {"X"} else {"O"};
            break;
        }
    }
    print_tab(game_tab) ;
}

fn print_tab(tab: &mut [&str; 9]) {

    println!("Board:\t+---+----+--+");
    println!("\t| {} | {} | {} |", tab[0], tab[1], tab[2]);
    println!("\t+---+---+---+");
    println!("\t| {} | {} | {} |", tab[3], tab [4], tab[5]);
    println!("\t+---+----+---+");
    println!("\t| {} | {} | {} |", tab[6], tab[7], tab[8]);
    println!("\t+---+---+---+\n");

}

fn check_three(tab: &mut [&str; 9], char: &str) -> bool {
    if tab[0] == char && tab[0] == tab[1] && tab[1] == tab[2]
        || tab[3] == char && tab[3] == tab[4] && tab[4] == tab[5]
        || tab[6] == char && tab[6] == tab[7] && tab[7] == tab[8]
        || tab[0] == char && tab[0] == tab[3] && tab[3] == tab[6]
        || tab[1] == char && tab[1] == tab[4] && tab[4] == tab[7]
        || tab[2] == char && tab[2] == tab[5] && tab[5] == tab[8]
        || tab[0] == char && tab[0] == tab[4] && tab[4] == tab[8]
        || tab[2] == char && tab[2] == tab[4] && tab[4] == tab[8] {
            true
        } else {
            false
        }
}

fn is_win(tab: &mut [&str; 9]) -> (bool, u8) {
    let mut all = true ;

    if check_three(tab, "X") {
        (true, 1)
    } else if check_three(tab, "O") {
        (true, 2)
    } else {
        for i in 0..tab.len() {
            if tab[i] != "X" && tab[i] != "O" {
                all = false;
            }
        }
        if all {
            (true, 0)
        } else {
            (false, 0)
        }
    }
}