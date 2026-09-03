#!/bin/bash

cd "/home/luis-das-artimanhas/IFES-SISTEMAS-DE-INFORMACAO" || exit 1

echo "================================"
echo "       GIT AUTOMÁTICO"
echo "================================"
echo

echo "🔍 Git status..."
git status

echo
echo "⬇️ Git pull..."
git pull || exit 1

echo
echo "📦 Git add..."
git add .

echo
echo "💾 Git commit..."
git commit -m "updated MD" || echo "ℹ️ Nenhuma alteração para commit."

echo
echo "⬆️ Git push..."
git push

echo
echo "================================"
echo "✅ CONCLUÍDO"
echo "================================"
echo

read -p "Pressione ENTER para fechar..."

