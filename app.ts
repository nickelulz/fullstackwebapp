import Express, { Request, Response } from 'express'
import logger from './logger'
import axios from 'axios'
import clic from 'cli-color'

const PORT = 3000;

const app = Express();
app.use(Express.static(__dirname + "/public/"));

app.listen(PORT, () => {
	logger.info(`Server now listening on port ${clic.green(PORT)}.`);
})

app.get('/', (req: Request, res: Response) => {
	logger.info(`Client ${clic.green(req.ip === '127.0.0.1' || req.ip === '::1' ? 'HOME' : req.ip)} connected to ${clic.green('/')}.`);
	res.sendFile('index.html');
});

// Backend interfacing endpoint
app.get('/server', (req: Request, res: Response) => {
	res.send('Hello from frontend!');
	logger.info(`Recieved request from backend. (${clic.green('/server/')})`);
});
