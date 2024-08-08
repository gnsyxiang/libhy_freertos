#!/usr/bin/env bash

# set -x

echo "-------------push origin commit"
git push origin main -f
echo ""

echo "-------------push origin tags"
git push origin --tags
echo ""

echo "-------------push gitee commit"
git push gitee main -f
echo ""

echo "-------------push gitee tags"
git push gitee --tags
echo ""

