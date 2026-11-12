// app_hibrido.rs
// Demonstração de Interoperabilidade (FFI): código Rust chamando função C nativa sem overhead
// Passos para compilar e linkar:
//   1. gcc -O2 -c sensor_c.c -o sensor_c.o
//   2. ar rcs libsensor_c.a sensor_c.o
//   3. rustc app_hibrido.rs -L . -lsensor_c -o app_hibrido && ./app_hibrido

unsafe extern "C" {
    fn calibrar_leitura_c(valor_bruto: i32, offset: i32) -> i32;
}

// Wrapper seguro em Rust que encapsula a chamada C
fn calibrar_seguro(leituras: &[i32], offset: i32) -> Vec<i32> {
    let mut resultado = Vec::with_capacity(leituras.len());
    for &bruto in leituras {
        // Chamada FFI confinada neste ponto:
        let calibrado = unsafe { calibrar_leitura_c(bruto, offset) };
        resultado.push(calibrado);
    }
    resultado
}

fn main() {
    let dados_sensor = [100, 250, 400];
    let processados = calibrar_seguro(&dados_sensor, -15);
    println!("[FFI C + Rust] Leituras calibradas pela rotina C: {:?}", processados);
}

