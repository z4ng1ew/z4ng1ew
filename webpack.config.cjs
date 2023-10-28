const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const MiniCssExtractPlugin = require('mini-css-extract-plugin');

module.exports = {
	entry: './src/index.ts',
	output: {
		path: path.resolve(__dirname, './dist'),
		filename: 'bundle.js',
		clean: true,
	},
	mode: 'development',
	plugins: [
		new HtmlWebpackPlugin({
			filename: './index.html',
			template: './src/index.html',
			inject: true,
		}),
		new MiniCssExtractPlugin({
			filename: '[name].css',
			chunkFilename: '[id].css',
		}),
	],
	module: {
		rules: [
			{
				test: /\.css$/i,
				use: [MiniCssExtractPlugin.loader, 'css-loader'],
			},
			{
				test: /\.tsx?$/,
				use: 'ts-loader',
				exclude: /node_modules/,
			},
		],
	},
	devServer: {
		open: true,
		liveReload: true,
		static: path.resolve(__dirname, './src'),
	},
	target: 'web',
};
