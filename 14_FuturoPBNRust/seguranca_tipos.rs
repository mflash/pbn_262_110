// seguranca_tipos.rs
// Demonstração de Option<T>, Result<T, E>, iteradores de custo zero e bloco 'unsafe' isolado
// Compile com: rustc -O seguranca_tipos.rs && ./seguranca_tipos

// 1. Ausência de NULL: Option<usize> obriga quem chama a tratar o caso 'None'
fn buscar_sensor(sensores: &[i32], alvo: i32) -> Option<usize> {
    for (indice, &valor) in sensores.iter().enumerate() {
        if valor == alvo {
            return Some(indice);
        }
    }
    None
}

// 2. Tratamento explícito de erros sem 'errno' global: Result<i32, &'static str>
fn dividir_seguro(a: i32, b: i32) -> Result<i32, &'static str> {
    if b == 0 {
        Err("Divisão por zero detectada!")
    } else {
        Ok(a / b)
    }
}

// 3. Isolamento de código de baixo nível com 'unsafe'
fn escrita_baixo_nivel(ptr: *mut u32, valor: u32) {
    // A auditoria manual de ponteiro fica restrita a este bloco explícito:
    unsafe {
        *ptr = valor; // Igual a *ptr = valor em C!
    }
}

fn main() {
    let sensores = [120, 450, 380, 910];

    // Pattern Matching exaustivo sobre Option<usize>
    match buscar_sensor(&sensores, 380) {
        Some(pos) => println!("[Option] Sensor encontrado na posição {}", pos),
        None      => println!("[Option] Sensor não localizado"),
    }

    // Pattern Matching sobre Result<T, E>
    match dividir_seguro(100, 0) {
        Ok(res)   => println!("[Result] Resultado = {}", res),
        Err(msg)  => println!("[Result] Erro tratado com segurança: {}", msg),
    }

    // Operação de baixo nível auditada
    let mut registrador: u32 = 0;
    escrita_baixo_nivel(&mut registrador as *mut u32, 0xCAFE_BABE);
    println!("[Unsafe] Registrador = 0x{:X}", registrador);
}

