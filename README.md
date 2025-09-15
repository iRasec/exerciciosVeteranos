🐳 1. Subida do ambiente local

Dentro do projeto ai-secretaria:

git clone https://github.com/iRasec/ai-secretaria.git
cd ai-secretaria
docker-compose up -d


📌 Conferir se os containers do Chatwoot subiram corretamente:

docker ps

Aplicação disponível em: http://localhost:3000/

<img width="700" height="1005" alt="Image" src="https://github.com/user-attachments/assets/992f3f5d-0a6d-4286-b6fa-fcb38c73c760" />

👥 2. Funcionalidades de agentes
Referências

[Como adicionar agentes](https://www.chatwoot.com/hc/user-guide/articles/1677482414-adding-agents)

[Como usar Agent Bots](https://www.chatwoot.com/hc/user-guide/articles/1677497472-how-to-use-agent-bots)

Principais pontos

Agentes são os usuários que atendem as conversas.

Papéis possíveis:

Administrator → gerencia configurações, inboxes e outros agentes.

Agent → atende conversas, mas não altera configs globais.

Agentes podem ser atribuídos a:

Inbox (caixas de entrada) → canais como WhatsApp, e-mail, site chat widget.

Teams (equipes) → grupos de agentes para organizar o atendimento.

<img width="1390" height="734" alt="Image" src="https://github.com/user-attachments/assets/5b912d05-03d3-4e11-96c3-bc5305b39c8a" />

🤖 3. Agent Bots

Funcionam como agentes automatizados dentro do Chatwoot.

Usados para respostas automáticas, triagem inicial ou integração com IA.

São configurados como um agente especial (bot) dentro da Inbox.

<img width="1338" height="832" alt="Image" src="https://github.com/user-attachments/assets/0ed86dc5-6085-45c8-b4d3-7f490177f653" />

<img width="629" height="477" alt="Image" src="https://github.com/user-attachments/assets/fa7af4ea-0151-4b60-aa15-9e47055d6414" />

📌 4. Principais características observadas

✅ Criação de agentes via painel → Settings > Agents.

✅ Atribuição de agentes às Inboxes e Teams.

✅ Permissões variam de acordo com o papel (admin vs agente).

✅ Agent Bots podem ser usados em Inboxes específicas para automação inicial.

✅ Status (online/offline) afeta o roteamento automático de conversas.


🔑 5. Pré-requisitos para habilitar agentes e bots

Conta Admin para gerenciar usuários.

Criar pelo menos uma Inbox (ex.: canal de chat, WhatsApp ou e-mail).

Adicionar agentes e atribuí-los à Inbox.

(Para bots) Ativar a opção de Agent Bot dentro da Inbox.

✅ Conclusão

O ambiente do ai-secretaria roda com sucesso em local via Docker.

Documentação revisada: criação e uso de agentes + bots entendidos.
