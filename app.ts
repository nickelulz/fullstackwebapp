import Express, { Request, Response } from 'express'
import logger from './logger'
import axios from 'axios'
import clic from 'cli-color'

const PORT = 3000;

const app = Express();
app.listen(PORT, () => {
	logger.info(`Server now listening on port ${clic.green(PORT)}.`);
})

app.get('/', (req: Request, res: Response) => {
	const ip = req.ip.substring(7);
	logger.info(`Client ${clic.green(ip === '127.0.0.1' ? 'HOME' : ip)} connected to ${clic.green('/')}.`);
	res.sendFile(__dirname + '/public/index.html');
});