#!/bin/bash

set -e

echo "🔍 === Git Auto ==="
git status

echo
echo "⬇️ Executando git pull..."
git pull

echo
echo "📦 Executando git add..."
git add .

echo
echo "💾 Executando git commit..."
git commit -m "updated MD" || echo "ℹ️ Nenhuma alteração para commit."

echo
echo "⬆️ Executando git push..."
git push

echo
echo "✅ Concluído!"

