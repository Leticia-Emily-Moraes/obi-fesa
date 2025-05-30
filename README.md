# 🧠 obi-fesa

Repositório com exercícios resolvidos da **Olimpíada Brasileira de Informática (OBI)**, desenvolvido por alunos da **Faculdade Engenheiro Salvador Arena (FESA)**. Nosso objetivo é estudar lógica, treinar algoritmos e nos preparar para competições como a OBI.

---

## 📁 Estrutura de Pastas

Os exercícios estão organizados por **ano**, depois por **nível** (iniciantes, júnior, sênior), **fase** (1ª fase, 2ª fase etc.), e por fim os arquivos dos exercícios resolvidos.

---

```
obi-fesa/
│
├── 2023/
│ ├── nivel-1/
│ │ ├── fase-1/
│ │ │ ├── exercicio1.c
│ │ │ ├── exercicio2.c
│ │ └── fase-2/
│ │ └── exercicio1.c
│ └── nivel-2/
│ └── fase-1/
│ └── exercicio1.cpp
│
├── 2024/
│ ├── nivel-1/
│ │ └── fase-1/
│ │ └── exercicio1.c
│ └── nivel-3/
│ └── fase-1/
│ └── exercicio1.py
│
└── README.md
```

---

> 📌 O nome do arquivo deve ser o nome do exercicio em snake-case, exemplo: `contas-a-pagar.py`

---

## 🚀 Como contribuir corretamente (passo a passo)

### ✅ 1. Clone o repositório (apenas na primeira vez)

```bash
git clone https://github.com/Leticia-Emily-Moraes/obi-fesa.git
cd obi-fesa
```

---

### 🔄 2. Sempre atualize a branch main antes de começar

```bash
git checkout main
git pull origin main
```

---

### 🌿 3. Crie uma nova branch para suas alterações

Crie uma branch com um nome descritivo. Exemplo para exercício da fase 1 do nível 1 de 2024:

```bash
git checkout -b 2024-nivel1-fase1
```

---

### 💻 4. Adicione o exercício na pasta correta
>Exemplo de caminho correto:

```bash
2024/nivel-1/fase-1/exercicio1.c
```

---

### 💾 5. Faça o commit das alterações

```bash
git add .
git commit -m "feat: adiciona exercício 1 da fase 1 - nível 1 (2024)"
```

---

### 📤 6. Envie a branch para o GitHub
```bash
git push origin 2024-nivel1-fase1
```

---

### 🔁 7. Crie o Pull Request (PR)
1. Vá até o repositório no GitHub.
2. Clique em "Compare & pull request".
3. Verifique se está da **sua branch** para a **`main`**.
4. Escreva uma descrição clara do que foi adicionado. De preferência, explique a lógica da resolução do exercício.
5. Clique em “Create pull request”.
---

## ⚠️ Dicas para evitar conflitos

- Atualize a branch `main` **antes** de começar qualquer alteração.
- Nunca faça commits diretamente na branch `main`.
- Faça **um PR por conjunto de exercícios**, preferencialmente por fase ou ano.
- Se tiver conflitos, entre em contato com o time para ajudar a resolver!

---
