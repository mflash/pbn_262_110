// ownership_borrowing.rs
// Demonstração prática de Ownership, Move, Borrowing (&T / &mut T) e Slices em Rust
// Compile e execute com: rustc ownership_borrowing.rs && ./ownership_borrowing

struct Sessao {
    id: u32,
    nivel_acesso: u8,
}

// Recebe um empréstimo imutável (&Sessao): pode ler, mas NÃO pode alterar nem destruir
fn inspecionar_sessao(s: &Sessao) {
    println!("[Borrow &T] Inspecionando sessão #{} (nível: {})", s.id, s.nivel_acesso);
}

// Recebe um empréstimo mutável exclusivo (&mut Sessao): único com permissão de escrita
fn elevar_privilegio(s: &mut Sessao) {
    s.nivel_acesso = 99;
    println!("[Borrow &mut T] Nível da sessão #{} elevado para {}", s.id, s.nivel_acesso);
}

// Fatia (&[i32]) carrega ponteiro + tamanho juntos (Fat Pointer)
fn somar_fatia(dados: &[i32]) -> i32 {
    let mut soma = 0;
    for &valor in dados {
        soma += valor;
    }
    soma
}

fn main() {
    // 1. Ownership e Move na Heap (Box equivale a malloc/free automático)
    let sessao_inicial = Box::new(Sessao { id: 101, nivel_acesso: 0 });

    // Transferência de posse (Move): 'sessao_ativa' assume a posse da memória
    let mut sessao_ativa = sessao_inicial;
    // Se tentarmos usar 'sessao_inicial' abaixo, o compilador barra (evita Use-After-Free!):
    // println!("{}", sessao_inicial.id); // ERRO DE COMPILAÇÃO: value borrowed here after move

    // 2. Empréstimos (Borrowing) respeitando Aliasing XOR Mutability
    inspecionar_sessao(&sessao_ativa);
    elevar_privilegio(&mut sessao_ativa);
    inspecionar_sessao(&sessao_ativa);

    // 3. Segurança Espacial com Slices (sem decaimento de ponteiro)
    let leituras: [i32; 5] = [10, 20, 30, 40, 50];
    let sub_fatia = &leituras[1..4]; // [20, 30, 40] -> tamanho = 3 conhecido!
    println!("[Slice &[i32]] Soma da fatia (len={}): {}", sub_fatia.len(), somar_fatia(sub_fatia));

    // Ao final de main(), 'sessao_ativa' sai de escopo e é liberada automaticamente (Drop)!
}

